// Assignment 1: Leeson Chen
// C++ program to generate 10 magic squares of dimension N specified by user
void summing(int **magicSquare, int N);
void base(int **magicSquare, int N);
void flipV(int **magicSquare, int N);
void flipH(int **magicSquare, int N);
void flipHV(int **magicSquare, int N);
void flipD(int **magicSquare, int N);
void flipVD(int **magicSquare, int N);
void flipHD(int **magicSquare, int N);
void flipHVD(int **magicSquare, int N);
#include <iostream>
#include <string.h>

int main() {
	int N;
	std::cout << "INPUT>> Enter the size of a magic square: ";
	std::cin >> N;
	
	// Error checking: makes sure N is a legal input
	if ((N % 2 == 0) || (N < 3) || (N > 15)) {
	std::cout << "Sorry, you must enter an odd integer between 3 and 15.";
	return 0;
	}
	
	//Main mathematical section of program
	else {
		// squaremaker #1 ( formerly a function, but it is simpler to create the array within main() );
			// creating 2D dynamic array (?)
			int ** magicSquare = new int*[N];
			for (int i = 0; i != N ; ++i) {
				magicSquare[i] = new int[N];
			}
			// Initializing all elements to 0
			for (int i = 0; i != N; i++) {
				for (int j = 0; j != N; j++) {
					magicSquare[i][j] = 0;
				}
			}
			// Here is the math that creates the magic square
			int i = N/2;
			int j = N-1;
			for (int num=1; num <= N*N; ) {
					if (i == -1 && j == N) { j = N-2; i = 0;} 
					else { 
						if (j == N) {j = 0;}
						if (i < 0) {i = N-1;}
						}
				if (magicSquare[i][j]) { j -= 2; i++; continue;} // I normally don't delete the whitespace but
				else { magicSquare[i][j] = num++; j++; i--;} //this code is so compact it is easier to read this way
			} 
		// end squaremaker #1
			
			std::cout << std::endl;
			
			// Main output
			// Instead of looping, I have individual commands because each flip is different and
			// uses the same base. Sorry that this is very obtuse.
			std::cout << "OUTPUT>> Magic Square #1 is: " << std::endl;
			base(magicSquare, N);
			summing(magicSquare, N);
			std::cout << std::endl << std::endl;
			std::cout << "OUTPUT>> Magic Square #2 is: " << std::endl;
			flipV(magicSquare, N);
			summing(magicSquare, N);
			std::cout << std::endl << std::endl;
			std::cout << "OUTPUT>> Magic Square #3 is: " << std::endl;
			flipH(magicSquare, N);
			summing(magicSquare, N);
			std::cout << std::endl << std::endl;
			std::cout << "OUTPUT>> Magic Square #4 is: " << std::endl;
			flipHV(magicSquare, N);
			summing(magicSquare, N);
			std::cout << std::endl << std::endl;
			std::cout << "OUTPUT>> Magic Square #5 is: " << std::endl;
			flipD(magicSquare, N);
			summing(magicSquare, N);
			std::cout << std::endl << std::endl;
			std::cout << "OUTPUT>> Magic Square #6 is: " << std::endl;
			flipVD(magicSquare, N);
			summing(magicSquare, N);
			std::cout << std::endl << std::endl;
			std::cout << "OUTPUT>> Magic Square #7 is: " << std::endl;
			flipHD(magicSquare, N);
			summing(magicSquare, N);
			std::cout << std::endl << std::endl;
			std::cout << "OUTPUT>> Magic Square #8 is: " << std::endl;
			flipHVD(magicSquare, N);
			summing(magicSquare, N);
			std::cout << std::endl << std::endl;
		
			if (N > 3) { // need 2 more magic squares
				// squaremaker #2, same code as squaremaker #1 but
				// changed starting location of num = 1
				int ** magicSquare2 = new int*[N];
				for (int i = 0; i != N ; ++i) {
					magicSquare2[i] = new int[N];
				}
				for (int i = 0; i != N; i++) {
					for (int j = 0; j != N; j++) {
						magicSquare2[i][j] = 0;
					}
				}
				int nsqr = N*N;
				int i=(N/2)-1, j=N/2;
              for (int k=1; k<=nsqr; ++k) {
              //std::cout << i << " " << j << " " << k << std::endl;
                  magicSquare2[i][j] = k;
                      if (k%N==0) { //previous k was multiple of N
                          i = (i-2)%N;//up 2
                      } else { //general 
                          i = (i-1)%N;//up
                          j = (j+1)%N;//right
                      }
                      
                      // loop negatives
                      if (i<0) {
                          i = i+N;
                      }
                      if (j<0) {
                          j = j+N;
                      }
              }
			std::cout << "OUTPUT>> Magic Square #9 is: " << std::endl;
			base(magicSquare2, N);
			summing(magicSquare, N);
			std::cout << std::endl << std::endl;
			std::cout << "OUTPUT>> Magic Square #10 is: " << std::endl;
			flipV(magicSquare2, N);
			summing(magicSquare, N);
			std::cout << std::endl << std::endl;
			} // end if (N > 3)
	} // end else
} // end main()
		
			
	// Flipping functions (8 total)
		// Base matrix
		void base(int ** magicSquare, int N) {
			//std::cout << "Base";
			std::cout << std::endl;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) 
					std::cout << magicSquare[i][j] << "	";
					std::cout << std::endl;
			}
			std::cout << std::endl;
		}
		
		// Flip vertically (left/right)
		void flipV(int ** magicSquare, int N) {
			//std::cout << "Flip vertically";
			std::cout << std::endl;
			for (int i = 0; i < N; i++) {
				for (int j = N-1; j >= 0; j--) 
					std::cout << magicSquare[i][j] << "	";
					std::cout << std::endl;
			}
			std::cout << std::endl;
		}
		
		// Flip horizontally (up/down)
		void flipH(int ** magicSquare, int N) {
			//std::cout << "Flip horizontally";
			std::cout << std::endl;
			for (int i = N-1; i >= 0; i--) {
				for (int j = 0; j < N; j++) 
					std::cout << magicSquare[i][j] << "	";
					std::cout << std::endl;
			}
			std::cout << std::endl;
		}
		
		// Flip horizontally and vertically
		void flipHV(int ** magicSquare, int N) {
			//std::cout << "Flip horizontally and vertically";
			std::cout << std::endl;
			for (int i = N-1; i >= 0; i--) {
				for (int j = N-1; j >= 0; j--) 
					std::cout << magicSquare[i][j] << "	";
					std::cout << std::endl;
			}
			std::cout << std::endl;
		}
		
		// Flip diagonally (i.e. transpose)
		void flipD(int ** magicSquare, int N) {
			//std::cout << "Flip diagonally";
			std::cout << std::endl;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) 
					std::cout << magicSquare[j][i] << "	";
					std::cout << std::endl;
			}
			std::cout << std::endl;
		}
		
		// Flip vertically and diagonally
		void flipVD(int ** magicSquare, int N) {
			//std::cout << "Flip vertically and diagonally";
			std::cout << std::endl;
			for (int i = 0; i < N; i++) {
				for (int j = N-1; j >= 0; j--) 
					std::cout << magicSquare[j][i] << "	";
					std::cout << std::endl;
			}
			std::cout << std::endl;
		}
			
		// Flip horizontally and diagonally
		void flipHD(int ** magicSquare, int N) {
			//std::cout << "Flip horizontally and diagonally";
			std::cout << std::endl;
			for (int i = N-1; i >= 0; i--) {
				for (int j = 0; j < N; j++) 
					std::cout << magicSquare[j][i] << "	";
					std::cout << std::endl;
			}
			std::cout << std::endl;
		}
		
		// Flip horizontally and vertically and diagonally
		void flipHVD(int ** magicSquare, int N) {
			//std::cout << "Flip horizontally and vertically and diagonally";
			std::cout << std::endl;
			for (int i = N-1; i >= 0; i--) {
				for (int j = N-1; j >= 0; j--) 
					std::cout << magicSquare[j][i] << "	";
					std::cout << std::endl;
			}
			std::cout << std::endl;
		}
	// end Flipping functions
		
				
				
				
		// Summing function
		void summing(int **magicSquare, int N) {
			std::cout << "OUTPUT>> Checking the sums of every row: 	";
			for (int i = 0; i < N; i++) {
				int tempSum = 0;
				for (int j = 0; j < N; j++) {
					tempSum = tempSum + magicSquare[i][j];
				}
				std::cout << tempSum << " ";
			} std::cout << std::endl;
			std::cout << "OUTPUT>> Checking the sums of every column: 	";
			for (int i = 0; i < N; i++) {
				int tempSum = 0;
				for (int j = 0; j < N; j++) {
					tempSum = tempSum + magicSquare[j][i];
				}
				std::cout << tempSum << " ";
			} std::cout << std::endl;
			std::cout << "OUTPUT>> Checking the sums of every diagonal: 	";
			int tempSum = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (i == j) { tempSum = tempSum + magicSquare[i][j];}
				}
			} std::cout << tempSum << " ";
			tempSum = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (i == (N-j-1)) { tempSum = tempSum + magicSquare[i][j];}
				}
			} std::cout << tempSum << " " << std::endl;
		} // end Summing function
		
				
			
