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


#ifndef INCLUDED_CSPL_SNR_FILE_SINK_B_H
#define INCLUDED_CSPL_SNR_FILE_SINK_B_H

#include <cspl/api.h>
#include <gr_sync_block.h>

namespace gr {
  namespace cspl {

    /*!
     * \brief Log bits and SNR to text file
     * \ingroup cspl
     *
     */
    class CSPL_API snr_file_sink_b : virtual public gr_sync_block
    {
     public:
      typedef boost::shared_ptr<snr_file_sink_b> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of cspl::snr_file_sink_b.
       *
       * To avoid accidental use of raw pointers, cspl::snr_file_sink_b's
       * constructor is in a private implementation
       * class. cspl::snr_file_sink_b::make is the public interface for
       * creating new instances.
       */
      static sptr make(const char* filename);
    };

  } // namespace cspl
} // namespace gr

#endif /* INCLUDED_CSPL_SNR_FILE_SINK_B_H */

