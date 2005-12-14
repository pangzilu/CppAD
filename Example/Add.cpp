/* -----------------------------------------------------------------------
CppAD: C++ Algorithmic Differentiation: Copyright (C) 2003-05 Bradley M. Bell

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
------------------------------------------------------------------------ */

/*
$begin Add.cpp$$

$section Binary Addition: Example and Test$$

$index add, example$$
$index example, add$$
$index test, add$$

$index plus, example$$
$index example, plus$$
$index test, plus$$

$code
$verbatim%Example/Add.cpp%0%// BEGIN PROGRAM%// END PROGRAM%1%$$
$$

$end
*/
// BEGIN PROGRAM

# include <CppAD/CppAD.h>
# include <cmath>

bool Add(void)
{	bool ok = true;

	using namespace CppAD;

	// independent variable vector
	double u0 = .5;
	CppADvector< AD<double> > U(1);
	U[0]      = u0; 
	Independent(U);

	AD<double> a = U[0] + 1.; // AD<double> + double
	AD<double> b = a  + 2;    // AD<double> + int
	AD<double> c = 3. + b;    // double     + AD<double> 
	AD<double> d = 4  + c;    // int        + AD<double> 

	// dependent variable vector 
	CppADvector< AD<double> > Z(1);
	Z[0] = d + U[0];          // AD<double> + AD<double> 

	// create f: U -> Z and vectors used for derivative calculations
	ADFun<double> f(U, Z); 
	CppADvector<double> v(1);
	CppADvector<double> w(1);

	// check value 
	ok &= NearEqual(Z[0] , 2 * u0 + 10,  1e-10 , 1e-10);

	// forward computation of partials w.r.t. u
	size_t j;
	size_t p     = 5;
	double jfac  = 1.;
	double value = 2.;
	v[0]         = 1.;
	for(j = 1; j < p; j++)
	{	jfac *= j;
		w     = f.Forward(j, v);	
		ok &= NearEqual(jfac*w[0], value, 1e-10 , 1e-10); // d^jz/du^j
		v[0]  = 0.;
		value = 0.;
	}

	// reverse computation of partials of Taylor coefficients
	CppADvector<double> r(p); 
	w[0]  = 1.;
	r     = f.Reverse(p, w);
	jfac  = 1.;
	value = 2.;
	for(j = 0; j < p; j++)
	{	ok &= NearEqual(jfac*r[j], value, 1e-10 , 1e-10); // d^jz/du^j
		jfac *= (j + 1);
		value = 0.;
	}

	return ok;
}

// END PROGRAM
