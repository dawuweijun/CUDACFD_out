/* dev_R2grid.h
 * R2 under discretization (discretize functor) to a thread block
 * Ernest Yeung  ernestyalumni@gmail.com
 * 20160728
 */
#ifndef __DEV_R2GRID_H__
#define __DEV_R2GRID_H__

#include "../commonlib/errors.h"

extern __constant__ int dev_Ld[2]; // L^{d=2} = (L_x,L_y) \in \mathbb{N}^2

class dev_Grid2d
{
	public:
		dim3 Ld;
	
		float *dev_rho;
		float *dev_rho_out;

		float2 *dev_u;
		float2 *dev_u_out;

		float2 *dev_p;
		float2 *dev_p_out;

		float *dev_E;
		float *dev_E_out;

		// constructor
		__host__ dev_Grid2d( dim3 );

//		__host__ ~dev_Grid3d();

		__host__ int NFLAT();
};

class dev_block3d
{
	public:
		unsigned int  N_is[3];

		__device__ dev_block3d(unsigned int N_x, unsigned int N_y, unsigned int N_z);

		__device__ int flatten(int i_x, int i_y, int i_z);
};

#endif // __DEV_R2GRID_H__
