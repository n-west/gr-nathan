/* -*- c++ -*- */

#define CSPL_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "cspl_swig_doc.i"

%{
#include "cspl/snr_file_sink_b.h"
%}


%include "cspl/snr_file_sink_b.h"
GR_SWIG_BLOCK_MAGIC2(cspl, snr_file_sink_b);
