%{
 #include <shogun/kernel/SparseKernel.h>
%}

%include <shogun/kernel/SparseKernel.h>

%template(SparseRealKernel) CSparseKernel<float64_t>;
%template(SparseWordKernel) CSparseKernel<uint16_t>;