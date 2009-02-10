/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 1999-2008 Soeren Sonnenburg
 * Copyright (C) 1999-2008 Fraunhofer Institute FIRST and Max-Planck-Society
 */

#ifndef _CHI2KERNEL_H___
#define _CHI2KERNEL_H___

#include "lib/common.h"
#include "kernel/SimpleKernel.h"
#include "features/Features.h"
#include "features/RealFeatures.h"

/** The Chi2 kernel operating on realvalued vectors computes
 * the chi-squared distance between sets of histograms. It
 * is a very useful distance in image recognition (used to detect objects).
 *
 * It is defined as
 * \f[
 * k({\bf x},({\bf x'})= e^{-\frac{1}{width} \sum_{i=0}^{l}\frac{(x_i-x'_i)^2}{(x_i+x'_i)}}
 * \f]
 *
 * */
class CChi2Kernel: public CSimpleKernel<float64_t>
{
	public:
		/** constructor
		 *
		 * @param size cache size
		 * @param width width
		 */
		CChi2Kernel(int32_t size, float64_t width);

		/** constructor
		 *
		 * @param l features of left-hand side
		 * @param r features of right-hand side
		 * @param width width
		 * @param size cache size
		 */
		CChi2Kernel(
			CRealFeatures* l, CRealFeatures* r, float64_t width, int32_t size);

		virtual ~CChi2Kernel();

		/** initialize kernel
		 *
		 * @param l features of left-hand side
		 * @param r features of right-hand side
		 * @return if initializing was successful
		 */
		virtual bool init(CFeatures* l, CFeatures* r);

		/** load kernel init_data
		 *
		 * @param src file to load from
		 * @return if loading was successful
		 */
		virtual bool load_init(FILE* src);

		/** save kernel init_data
		 *
		 * @param dest file to save to
		 * @return if saving was successful
		 */
		virtual bool save_init(FILE* dest);

		/** return what type of kernel we are
		 *
		 * @return kernel type CHI2
		 */
		virtual EKernelType get_kernel_type() { return K_CHI2; }

		/** return the kernel's name
		 *
		 * @return name Chi2
		 */
		virtual const char* get_name() const { return "Chi2"; }

	protected:
		/** compute kernel function for features a and b
		 * idx_{a,b} denote the index of the feature vectors
		 * in the corresponding feature object
		 *
		 * @param idx_a index a
		 * @param idx_b index b
		 * @return computed kernel function at indices a,b
		 */
		virtual float64_t compute(int32_t idx_a, int32_t idx_b);

	protected:
		/** width */
		float64_t width;
};

#endif /* _CHI2KERNEL_H__ */

