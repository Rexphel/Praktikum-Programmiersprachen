//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

int calcDistance(const Vektor vEarthSurface, const Vektor vHuman, double dstepSizeRad=0);
void calcStepSize(double* dstepSize);

/**
 * @brief Main function. Runs all Tasks for this Experiment.
 *
 * Tests implemented functions sub, leange, skalarprodukt, winkel of Vektor.
 * Also Launches calcDistance.
 *
 * @return
 */

int main()
{
    Vektor vector1(1, 0, 0);
    Vektor vector2(0, 1, 0);
    Vektor vector3(4, 2, 3);

    vector1.ausgabe();
    vector2.ausgabe();


    std::cout << "Vektor länge: " << vector3.laenge() << std::endl;

    Vektor vectorsub = vector3.sub(vector2);
    vectorsub.ausgabe();

    std::cout << "Vektor2/3 Skalarprodukt: " << vector3.skalarProd(vector2) << std::endl;
    double winkel = vector3.winkel(vector2);
    std::cout << "Vektor2/3 Winkel: " << winkel << std::endl;
    std::cout << "Vektor3 vor Rotation: " << std::endl;
    vector3.ausgabe();
    vector3.rotiereUmZ(winkel);
    std::cout << "Vektor3 nach Rotation: " << std::endl;
	vector3.ausgabe();

	calcDistance(Vektor(6371,0,0), Vektor(.5574,0,0), 0.00000001);
	calcDistance(Vektor(6371,0,0), Vektor(.5574,0,0));


    return 0;

}

/**
 * @brief Calculates the Distance, a POV can view on a Sphere.
 *
 * @param vEarthSurface Vektor from origin to Earths Surface.
 * @param vHuman		Vektor from origin to POV of the Observer.
 * @param dstepSizeRad	Optional: Stepsize for the Calculation. Common: 0.00000001. If not given: automatic Calculation
 * @return Error Codes: 0 == All good; 1 == Error
 */

int calcDistance(const Vektor vEarthSurface,const Vektor vHuman, double dstepSizeRad){

	const Vektor vViewpoint = vEarthSurface.add(vHuman);
	Vektor vRotation = vEarthSurface;
	Vektor vDistance(0, 0, 0);
	bool brotationDirction = true; 								// Direction for rotation. Bool == True/Positive, == False/Negative
	int iter = 1;
	dstepSizeRad = dstepSizeRad==0 ? 0.01:dstepSizeRad;
	double* dstepSize = &dstepSizeRad;

	while(true){
		vDistance = vViewpoint.sub(vRotation);
		if((1-std::abs(vRotation.skalarProd(vDistance)))>0.99){
			std::cout << std::fixed << std::setprecision(12)
					<< "Sie können " << vDistance.laenge() << " Kilo Meter weit sehen." << std::endl
					<< "Sie sind " << vHuman.laenge() << " Kilo Meter hoch." << std::endl
					<< "Der Winkel beträgt ~" << vRotation.winkel(vViewpoint)* (180.0/3.141592653589793238463) << "° mit " << iter << " Iteratrionen" << std::endl;
			return 0;
		}

		std::cout << "Winkel: "<< vViewpoint.winkel(vRotation)* (180.0/3.141592653589793238463) << " Skalar: " << vRotation.skalarProd(vDistance) << std::endl;
		vRotation.rotiereUmZ(*dstepSize);
		iter++;
		if((vRotation.skalarProd(vDistance)<0 && brotationDirction)||(vRotation.skalarProd(vDistance)>0 && !brotationDirction)){
			std::cout << "Stepsize to large. Overstep. Change direction" << std::endl;
			brotationDirction=!brotationDirction;
			calcStepSize(dstepSize);
		}
	}
	return 1;
}

/**
 * @brief Calculates the stepsize for the next Iteration. Is used if no dstepSize is not given
 * 		  if Direction is switched add one Precision level.
 *
 * @param dstepSize Pointer to the Step Size to be edited.
 */
void calcStepSize(double* dstepSize){
	*dstepSize = *dstepSize*-0.1;
}



