/* -*- c++ -*- */
/* 
 * Copyright 2013 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gr_io_signature.h>
#include "snr_file_sink_b_impl.h"
#include <cstdio>
#include <boost/format.hpp>

namespace gr {
  namespace cspl {

    snr_file_sink_b::sptr
    snr_file_sink_b::make(const char* filename)
    {
      return gnuradio::get_initial_sptr (new snr_file_sink_b_impl(filename));
    }

    /*
     * The private constructor
     */
    snr_file_sink_b_impl::snr_file_sink_b_impl(const char* filename)
      : gr_sync_block("snr_file_sink_b",
		      gr_make_io_signature(1, 1, sizeof(char)),
		      gr_make_io_signature(0, 0, 0))
    {
       if (!open(filename))
            throw std::runtime_error ("cannot open file");
    }

    bool snr_file_sink_b_impl::open(const char* filename)
    {
        _file = fopen(filename, "w");
        if (_file < 0)
            return false;
        else
            return true;
    }

    /*
     * Our virtual destructor.
     */
    snr_file_sink_b_impl::~snr_file_sink_b_impl()
    {
        fclose(_file);
    }

    int
    snr_file_sink_b_impl::work(int noutput_items,
			  gr_vector_const_void_star &input_items,
			  gr_vector_void_star &output_items)
    {
        char *in = (char *) input_items[0];
        uint64_t start_N = nitems_read(0);
        uint64_t end_N = start_N + (uint64_t)(noutput_items);
        pmt::pmt_t snrkey = pmt::pmt_string_to_symbol("snr");

        std::vector<gr_tag_t> snr_tags;
        get_tags_in_range(snr_tags, 0, start_N, end_N, snrkey);
        // gr_block::get_tags_in_range(std::vector<pmt::pmt_t> &v,
        //                              unsigned int which_output,
        //                              uint64_t start,
        //                              uint64_t stop,
        //                              const pmt::pmt_t &key )

        float values[snr_tags.size()];
        uint64_t offsets[snr_tags.size()];
        for ( int ii=0; ii < snr_tags.size(); ii++)
        {
//            std::cout << "there's 1 tag" << std::endl;
//            std::cout <<  boost::format("SNR = %f db, sample offset %u")
//                 % snr_tags[ii].value
//                 % snr_tags[ii].offset
//             << std::endl;
            values[ii]  =  pmt::pmt_to_double(snr_tags[ii].value);
            offsets[ii] =  snr_tags[ii].offset;
        }
        int i_tag = 0;
        for (int idx=0; idx < noutput_items; idx++)
        {
            if (offsets[i_tag] == (start_N + idx))
            {
                fprintf(_file, "\n%f\n", values[i_tag]);
                i_tag++;
            }
            fprintf(_file, "%x", in[idx]);
        }
        
        // Tell runtime system how many output items we produced.
        return noutput_items;
    }

  } /* namespace cspl */
} /* namespace gr */

