#include "Disparity_SG.h"
#include "Calibration.h"


int main()
{
	/*calibration juli_calibration(9, 6, 24, 25, 320, 240);
	juli_calibration.calibrate();
	juli_calibration.save_calibration_result();*/

	disparity_SGBM juli_disparity_SG(320, 240);
	juli_disparity_SG.calculate_disparity_320x240();

	return 0;
}