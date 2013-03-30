
import scipy
from gnuradio import gr, digital
import cspl

N = 10e5
ntag = 10e1
gr_est = digital.SNR_EST_M2M4

bits = tuple(range(0,255))*100

SNR = 10.0**(10/10.0) # 5dB
scale = scipy.sqrt(SNR)

src = gr.vector_source_b(bits, False)
mod = digital.bpsk_mod()
chn = gr.channel_model(1.0/scale)
snr = digital.mpsk_snr_est_cc(gr_est)
demod = digital.bpsk_demod()
snk = cspl.snr_file_sink_b("data.foo")
tb = gr.top_block()
tb.connect(src, mod, chn, snr, demod, snk)
tb.run()

