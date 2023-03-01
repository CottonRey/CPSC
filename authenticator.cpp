#include <iostream>

using namespace std;

int main()
{
  const char correctCode1 = 'E';
  const char correctCode2 = 'C';
  const char correctCode3 = 'A';
  const int correctCheckSum = 5;
  char userCode1;
  char userCode2;
  char userCode3;
  int userCodeValue1;
  int userCodeValue2;
  int userCodeValue3;
  int userCodeValueSum;
  int userCheckSum;
  string correctCode;
  string userCode;

  cout << "Enter the first character of the message code:" << endl;
  cin >> userCode1;
  userCodeValue1 = int(userCode1);
  cout << "Enter the second character of the message code:" << endl;
  cin >> userCode2;
  userCodeValue2 = int(userCode2);
  cout << "Enter the third character of the message code:" << endl;
  cin >> userCode3;
  userCodeValue3 = int(userCode3);
  userCodeValueSum = (userCodeValue1 + userCodeValue2 + userCodeValue3);
  userCheckSum = ((userCodeValue1 + userCodeValue2 + userCodeValue3) % 7);

  cout << endl;

  correctCode += correctCode1;
  correctCode += correctCode2;
  correctCode += correctCode3;
  cout << "Authenticator code: " << correctCode << endl;

  userCode += userCode1;
  userCode += userCode2;
  userCode += userCode3;
  cout << "Message code: " << userCode << endl;

  cout << endl;
  if ((correctCode1 == userCode1) && (correctCode2 == userCode2) && (correctCode3 == userCode3)){
    cout << "Message is authentic." << endl;
  } else {
    cout << "Message is invalid." << endl;
  }

  if (correctCode == userCode){
    cout << "Concurrence: Message is authentic." << endl;
  } else {
    cout << "Concurrence: Message is invalid." << endl;
  }

  cout << endl;

  cout << "Characterization of Message Code" << endl;
  cout << "--------------------------------" << endl;

  cout << "ASCII Values of Message Code Characters: " << userCodeValue1 << ", " << userCodeValue2 << ", " << userCodeValue3 << endl;
  cout << "Sum of ASCII Values for Message Code Characters: " << userCodeValueSum << endl;

  if (userCheckSum == correctCheckSum){
    cout << "Message Code Checksum is valid: " << correctCheckSum << endl;
  } else {
    cout << "Message Code Checksum is invalid: " << userCheckSum << "; expected: " << correctCheckSum << endl;
  }

  if (userCode1 != correctCode1){
    cout << "First characters do not match: Message: " << userCode1 << "; Authenticator: " << correctCode1 << endl;
  }
  if (userCode2 != correctCode2){
    cout << "Second characters do not match: Message: " << userCode2 << "; Authenticator: " << correctCode2 << endl;
  }
  if (userCode3 != correctCode3){
    cout << "Third characters do not match: Message: " << userCode3 << "; Authenticator: " << correctCode3 << endl;
  }

  if (correctCode != userCode){
    if (correctCode > userCode){
      cout << "Message code (" << userCode << ") is lexicographically less than Authenticator code (" << correctCode << ")" << endl;
    } else {
      cout << "Message code (" << userCode << ") is lexicographically greater than Authenticator code (" << correctCode << ")" << endl;
    }
  }

  return 0;
}
