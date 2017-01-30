# ifndef CPPAD_UTILITY_SPARSE_RCV_HPP
# define CPPAD_UTILITY_SPARSE_RCV_HPP
/* --------------------------------------------------------------------------
CppAD: C++ Algorithmic Differentiation: Copyright (C) 2003-17 Bradley M. Bell

CppAD is distributed under multiple licenses. This distribution is under
the terms of the
                    Eclipse Public License Version 1.0.

A copy of this license is included in the COPYING file of this distribution.
Please visit http://www.coin-or.org/CppAD/ for information on other licenses.
-------------------------------------------------------------------------- */
# endif

/*
------------------------------------------------------------------------------
$begin sparse_rcv$$
$spell
	CppAD
	nr
	nc
	const
	var
	nnz
	cppad
	hpp
	rcv
	rc
$$
$section Sparse Matrix Row, Column, Value Representation$$

$head Under Construction$$
This class is under construction and not yet appropriation for public use.

$head Syntax$$
$codei%# include <cppad/utility/sparse_rcv.hpp>
%$$
$codei%sparse_rcv %matrix%(%nr%, %nc%, %pattern%, %val_in%)
%$$
$icode%nr%  = %matrix%.nr()
%$$
$icode%nc%  = %matrix%.nc()
%$$
$codei%const %Vector%<size_t>& %row%( %pattern%.row() )
%$$
$codei%const %Vector%<size_t>& %col%( %pattern%.col() )
%$$
$codei%const %Vector%<%Scalar%>& %val%( %matrix%.val() )
%$$
$icode%Vector%<%Scalar%>& %val_var%( %matrix%.val() )
%$$

$head Vector$$
We use $cref/Vector/sparse_rc/Vector/$$ to denote the
$cref SimpleVector$$ template class corresponding to $icode pattern$$.

$head Scalar$$
We use $icode Scalar$$ to denote the type of elements in the sparse matrix.

$head nr$$
This argument and return value has prototype
$codei%
	size_t %nr%
%$$
and is the number of rows in the matrix.
The object $icode matrix$$ is $code const$$
when $icode nr$$ is the return value.

$head nc$$
This argument and return value has prototype
$codei%
	size_t %nc%
%$$
and is the number of columns in the matrix.
The object $icode matrix$$ is $code const$$
when $icode nc$$ is the return value.

$head pattern$$
This argument has prototype
$codei%
	const sparse_rc<%Vector%>& %pattern%
%$$
It specifies the pattern for the non-zero entries in the sparse matrix.

$head nnz$$
We use the notation $icode nnz$$ to denote the number of
possibly non-zero entries in the pattern; i.e.,
$icode%pattern%.row().size()%$$.

$head val_in$$
This argument has prototype
$codei%
	const %Vector%<%Scalar%>& %val_in%
%$$
It muse have size $icode nnz$$ and specifies the initial values
for the non-zero elements in the sparse matrix.
To be specific,
for $icode%k% = 0, %...%, %nnz%-1%$$,
$icode%val_in%[%k%]%$$ is the initial value for the element with
row index $icode%row%[%k%]%$$ and column index $icode%col%[%k%]%$$.

$head row$$
This vector contains the row indices for the possibly non-zero entries
in the sparse matrix (as specified by $icode pattern$$).

$head col$$
This vector contains the column indices for the possibly non-zero entries
in the sparse matrix (as specified by $icode pattern$$).

$head val$$
This vector has the same size as $icode row$$ and
contains the current values for the possibly non-zero entries
in the sparse matrix.

$head val_var$$
This vector has the same properties as $icode val$$ and
in addition, you can change to value of the elements of the vector
with the following assignment
$codei%
	%val_var%[%k%] = %s%
%$$
where $icode k$$ is less than $icode nnz$$ and $icode s$$
is a $icode Scalar$$ object.

$end
*/
/*!
\file sparse_rcv.hpp
A sparse matrix class.
*/

namespace CppAD { // BEGIN CPPAD_NAMESPACE

/// Sparse matrices with elements of type Scalar
template < template<class> class Vector , class Scalar >
class sparse_rcv : public sparse_rc<Vector> {
private:
	/// val_[k] is the value for the k-th possibly non-zero entry in the matrix
	Vector<Scalar>   val_;
	/// number of rows in the matrix
	const size_t   nr_;
	/// number of columns in the matrix
	const size_t   nc_;
public:
	// ------------------------------------------------------------------------
	/// constructor
	sparse_rcv(
		size_t                   nr      ,
		size_t                   nc      ,
		const sparse_rc<Vector>& pattern ,
		const Vector<Scalar>&    val_in  )
	:
	sparse_rc<Vector>(pattern)     ,
	val_(val_in)                   ,
	nr_(nr)                        ,
	nc_(nc)
	{
# ifndef NDEBUG
		size_t nnz = sparse_rc<Vector>::row().size();
		CPPAD_ASSERT_KNOWN(
		val_in.size() == nnz ,
		"sparse_rcv: size of val_in is not equal number non-zeros in pattern"
		);
		for(size_t k = 0; k < nnz; k++)
		{	CPPAD_ASSERT_KNOWN(
				sparse_rc<Vector>::row()[k] < nr,
				"sparse_rcv: a pattern row index is not less than nr"
			);
			CPPAD_ASSERT_KNOWN(
				sparse_rc<Vector>::col()[k] < nc,
				"sparse_rcv: a pattern column index is not less than nc"
			);
		}
# endif
	}
	// ------------------------------------------------------------------------
	/// number of rows in matrix
	size_t nr(void) const
	{	return nr_; }
	/// number of columns in matrix
	size_t nc(void) const
	{	return nc_; }
	/// value vector
	const Vector<Scalar>& val(void) const
	{	return val_; }
	Vector<Scalar>&  val(void)
	{	return val_; }
};

} // END_CPPAD_NAMESPACE