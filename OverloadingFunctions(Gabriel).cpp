// This program will give you the area of a circle, a rectangle, and a triangle.
// In order to get the area of a circle, it will ask you for the radius of the circle which has to be positive.
// In order to get the area of a rectangle, the program will ask you for the length and width of the rectangle.
// Both length and width need to be positive. In order to get the area of a triangle, the program will ask you
// for the length of the three sides of the triangle. All three sides need to be positive. The program will also 
// validate if the triangle is a valid triangle. If it is not a valid triangle, you will get an error and be asked
// to try again.
// Function and by reference practice
// By Gabriel Perez

#include <iostream>
using namespace std;

void printBanner();
double area(double x);
double area(double x, double y);
double area(double x, double y, double z);
double getPosNum();
char getYorN();
void getValidTriangle(double& x, double& y, double& z);

int main() {
	system("Color 1F");
	system("Title Area Overloading Project with Input Validation     by Gabriel Perez");

	double radius, length, width, side1, side2, side3;
	char yes;

	printBanner();

	cout << "\nDo you want to test the program? ";
	yes = getYorN();

	while (yes == 'y' || yes == 'Y') {
		cout << "\nGive me the radius of your circle: ";
		radius = getPosNum();

		cout << "\tThe area of the circle is " << area(radius);

		cout << "\n\nGive me the length of your rectangle: ";
		length = getPosNum();

		cout << "... and the width: ";
		width = getPosNum();

		cout << "\t The area of the rectangle is: " << area(length, width);

		cout << "\n\nGive me the lengths of the sides of the triangle.";
		cout << "\nSide 1: ";
		side1 = getPosNum();
		cout << "Side 2: ";
		side2 = getPosNum();
		cout << "Side 3: ";
		side3 = getPosNum();

		getValidTriangle(side1, side2, side3);

		cout << "\tThe area of the triangle is: " << area(side1, side2, side3) << endl;

		cout << "\n\t ******************";

		cout << "\n\nDo you want to test the program again? ";
		yes = getYorN();
	}

	if (yes == 'n' || yes == 'N') {
		cout << "\nDon't you love Geometry?" << endl;
		return 0;
	}
	return 0;
}

void printBanner() {
	cout << "\n"
		<< "\t\t        Project on Designing Overloading Functions       \n"
		<< "\t\t     Find the area of a circle, rectangle, or triangle   \n"
		<< "\t\t            also does extensive input validation         \n"
		<< "\t\t               and uses by reference variables           \n"
		<< "\t\t                      by Gabriel Perez                   \n";
}

double area(double x) {    //DONE
	return x * x * 3.14159265359;
}

double area(double x, double y) {  // DONE
	return x * y;
}

double area(double x, double y, double z) {  // DONE
	double semi = (x + y + z) / 2;
	return sqrt(semi * (semi - x) * (semi - y) * (semi - z));
}

double getPosNum() {
	double a;

	cin >> a; cin.ignore(100, '\n');

	while (a < 1) {
		cout << "Positive numbers only please. Try again: ";
		cin >> a; cin.ignore(100, '\n');
	}
	return a;
}

char getYorN() {  // DONE
	char x;

	cin >> x; cin.ignore(100, '\n');

	while (x != 'Y' && x != 'y' && x != 'N' && x != 'n') {
		cout << "Please type in Y or N. Try again: ";
		cin >> x; cin.ignore(100, '\n');
	}
	return x;
}

void getValidTriangle(double &x, double &y, double &z) {

	while (x + y <= z || x + z <= y || y + z < x) {
		cout << "The sum of two sides of a triangle must be greater than the third side."
			<< "\nTry again. Side 1: ";
		x = getPosNum();
		cout << "Side 2: ";
		y = getPosNum();
		cout << "Side 3: ";
		z = getPosNum();
	}
}