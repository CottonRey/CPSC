#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
  double referenceFrequency = 16.35;
  double speedOfSound = 345.0;
  double fractionAmount = 0.0;
  double octave = 0.0;
  double calculatedFrequency = 0.0;
  double calculatedWavelength = 0.0;

  cout << "Reference Frequency: " << referenceFrequency << " Hz" << endl;
  cout << "Speed of Sound: " << speedOfSound << " m/s" << endl;

  octave = 0.0;
  fractionAmount = 0.0 / 12.0;
  calculatedFrequency = (referenceFrequency * pow(2, octave) * pow(2, fractionAmount));
  calculatedWavelength = ((speedOfSound / calculatedFrequency) * 100);
  cout << "Note: C0; nu: 0; k: 0; frequency: " << calculatedFrequency << "Hz; wavelength: " << calculatedWavelength << " cm" << endl;

  octave = 0.0;
  fractionAmount = 1.0 / 12.0;
  calculatedFrequency = (referenceFrequency * pow(2, octave) * pow(2, fractionAmount));
  calculatedWavelength = ((speedOfSound / calculatedFrequency) * 100);
  cout << "Note: C#0; nu: 0; k: 1; frequency: " << calculatedFrequency << "Hz; wavelength: " << calculatedWavelength << " cm" << endl;

  octave = 0.0;
  fractionAmount = 2.0 / 12.0;
  calculatedFrequency = (referenceFrequency * pow(2, octave) * pow(2, fractionAmount));
  calculatedWavelength = ((speedOfSound / calculatedFrequency) * 100);
  cout << "Note: D0; nu: 0; k: 2; frequency: " << calculatedFrequency << "Hz; wavelength: " << calculatedWavelength << " cm" << endl;

  octave = 4.0;
  fractionAmount = 0.0 / 12.0;
  calculatedFrequency = (referenceFrequency * pow(2, octave) * pow(2, fractionAmount));
  calculatedWavelength = ((speedOfSound / calculatedFrequency) * 100);
  cout << "Note: C4; nu: 4; k: 0; frequency: " << calculatedFrequency << "Hz; wavelength: " << calculatedWavelength << " cm" << endl;

  octave = 7.0;
  fractionAmount = 3.0 / 12.0;
  calculatedFrequency = (referenceFrequency * pow(2, octave) * pow(2, fractionAmount));
  calculatedWavelength = ((speedOfSound / calculatedFrequency) * 100);
  cout << "Note: D#7; nu: 7; k: 3; frequency: " << calculatedFrequency << "Hz; wavelength: " << calculatedWavelength << " cm" << endl;

  octave = 8.0;
  fractionAmount = 0.0 / 12.0;
  calculatedFrequency = (referenceFrequency * pow(2, octave) * pow(2, fractionAmount));
  calculatedWavelength = ((speedOfSound / calculatedFrequency) * 100);
  cout << "Note: C8; nu: 8; k: 0; frequency: " << calculatedFrequency << "Hz; wavelength: " << calculatedWavelength << " cm" << endl;
}
