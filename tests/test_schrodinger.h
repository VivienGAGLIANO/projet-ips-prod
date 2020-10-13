#include <cxxtest/TestSuite.h>
#include "../src/Schrodinger.cpp"
#include "../src/Hermit.cpp"
#include "../src/MathTools.cpp"
#include <armadillo>
#include <typeinfo>

class TestSchrodinger : public CxxTest::TestSuite
{
	public:
	void testSchrodingerPSI(void)
	{
		Schrodinger schro;
		Hermit herm(arma::colvec({6,4,9,3,0,-1,-2}));
		arma::colvec value = arma::exp(arma::colvec({-18})) * arma::sqrt(arma::colvec({6})) * herm.get(4)(0) / 48;
		TS_ASSERT_DELTA(schro.psi(4,{6})(0), value(0) , 0.000000000001);
		value = arma::exp(arma::colvec({-8}))* herm.get(0)(1);
		TS_ASSERT_DELTA(schro.psi(0,{4})(0),value(0),0.000000000001);
		value = arma::exp(arma::colvec({-81/2})) * arma::sqrt(arma::colvec({3})) * herm.get(3)(2) / 12;
		TS_ASSERT_DELTA(schro.psi(3,{9})(0),value(0),0.000000000001);
		value = arma::exp(arma::colvec({-9/2})) * arma::sqrt(arma::colvec({2})) * herm.get(1)(3) / 2;
		TS_ASSERT_DELTA(schro.psi(1,{3})(0),value(0),0.000000000001);
		value = arma::sqrt(arma::colvec({15})) * herm.get(5)(4) / 240;
		TS_ASSERT_DELTA(schro.psi(5,{0})(0),value(0),0.000000000001);
		value = arma::exp(arma::colvec({-1/2})) * arma::sqrt(arma::colvec({2})) * herm.get(1)(5) / 2;
		TS_ASSERT_DELTA(schro.psi(1,{-1})(0),value(0),0.000000000001);
		value = arma::exp(arma::colvec({-2})) * arma::sqrt(arma::colvec({6})) * herm.get(4)(6) / 48;
		TS_ASSERT_DELTA(schro.psi(4,{-2})(0),value(0),0.000000000001);
	}
	void testSchrodingerPSI_SECOND(void)
	{
		Schrodinger schro;
		int j =0;
		int i =0;
		const double h = 1e-10; 
		arma::colvec z = arma::colvec({-2,-1,0,1,2,5});
		arma::vec h_vec = arma::vec(z.n_rows).ones();
		for( i = 0; i < 8; i++) {
			arma::colvec value = (schro.psi(i, z + 2* h_vec) - 2 * schro.psi(i, z+h_vec) + schro.psi(i, z)) % ((1 / h*h)*h_vec);
			for (j = 0; j<6; j++) {
				TS_ASSERT_DELTA(schro.psi_second(i,z)(j),value(j),0.00000001);
			};
		};
	}

	void testSchrodingerPSI_ENERGY(void)
	{
		Schrodinger schro;
	    int j =0;
		int i =0;
		arma::colvec z = arma::colvec({-2,-1,0,1,2,5});
		arma::vec h_vec = arma::vec(z.n_rows).ones();
		for( i = 0; i < 8; i++) {
			arma::colvec value = (schro.psi_second(i,z)+schro.psi(i,z)%schro.psi(i,z)) % (0.5*h_vec);
			for (j = 0; j<6; j++) {
				TS_ASSERT_DELTA(schro.energy(i,z)(j),value(j),0.00000001);
			};
		};
	}
};
