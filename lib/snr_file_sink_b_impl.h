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

#ifndef INCLUDED_CSPL_SNR_FILE_SINK_B_IMPL_H
#define INCLUDED_CSPL_SNR_FILE_SINK_B_IMPL_H

#include <cspl/snr_file_sink_b.h>

namespace gr {
  namespace cspl {

    class snr_file_sink_b_impl : public snr_file_sink_b
    {
     private:
      // Nothing to declare in this block.
        FILE* _file;
        bool open(const char* filename);

     public:
      snr_file_sink_b_impl(const char* filename);
      ~snr_file_sink_b_impl();

      // Where all the action really happens
      int work(int noutput_items,
	       gr_vector_const_void_star &input_items,
	       gr_vector_void_star &output_items);
    };

  } // namespace cspl
} // namespace gr

#endif /* INCLUDED_CSPL_SNR_FILE_SINK_B_IMPL_H */

