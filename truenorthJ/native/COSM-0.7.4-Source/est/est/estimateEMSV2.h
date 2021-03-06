/****************************************************************************
 * Copyright (c) 2007 Einir Valdimarsson and Chrysanthe Preza
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 ****************************************************************************/
#ifndef _ESTIMATE_EMSV2_H
#define _ESTIMATE_EMSV2_H

#include "estimateIterative.h"
#include <complex>
#include "fftwInterface.h"

namespace cosm {

template<typename T, int N>
class EstimateEMSV2 : public EstimateIterative<T,N> {

  public:

    // class constructor
    EstimateEMSV2(
	Array< RectDomain<N>, 1>& strata,
	Array< Array<T,N>, 1>& psf,
	Array<T,N>& img,
	int iterations,
	T epsilon = 1E-4
    );

    // class destructor
    virtual ~EstimateEMSV2() { };

    // Function to specify the raw image
    virtual void setImage( 
	Array<T,N>& img 
    );

  protected:

    // Function for single iteration of the algorithm
    virtual void iterate();

  private:

    // not allowed
    EstimateEMSV2( EstimateEMSV2<T,N>& );
    void operator=( EstimateEMSV2<T,N>& );

    // Function to specify the psf
    virtual void setPSF( 
	Array<T,N>& psf 
    );
 
  protected:
    
    T epsilon_;				
    fftwInterface<T,N> fftw_;
    Array<Array<std::complex<T>,N>, 1> psfsF_;    
    Array<T,N> s_;		
    Array<T,N> s1_;		
    Array<T,N> s2_;		
    Array<std::complex<T>,N> estF_;  
    Array<std::complex<T>,N> sF_;  
    Array<RectDomain<N>, 1> strata_;
    Array<T,1> a_;
    T scale_;
};

}

#include "estimateEMSV2.c"

#endif  // _ESTIMATE_EMSV2_H
