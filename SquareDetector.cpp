#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

int matVisited[21][21];

bool isSquarePresent( vector< string > matrix ) {
	bool squarePresent( false );
	for( unsigned i = 0; i < matrix.size(); ++i ) {
		for( unsigned j = 0; j < matrix[0].length(); ++j ) {
			if( matrix[i][j] == '#' ) {
				if( squarePresent ) {
					if( ! matVisited[i][j] )
						return false;
					else
						continue;
				}//if( squarePresent );
				else {
					unsigned k(0);
					for( k = j; k < matrix[0].length(); ++k ) {
						if( matrix[i][k] != '#' )
							break;
					}
					if( i + k - j > matrix.size() ) return false;
					
					for( unsigned m = i; m < i + k - j; ++m )
						for( unsigned n = j; n < k; ++n )
							if( matrix[m][n] == '#' )
								matVisited[m][n] = 1;
							else
								return false;
					squarePresent = true;
				}//else
			}//if 
		}//for( j );
	}//for( i );
	return squarePresent;
}

int main() {
	unsigned numOfTestCases(0);
	vector< bool > finalResult;
	cin >> numOfTestCases;
	
	for( unsigned k = 0; k < numOfTestCases; ++k ) {
		unsigned matSize(0);
		cin >> matSize;
		vector< string > matrix;
		string temp("");
		for( unsigned m = 0 ; m < matSize; ++m ) {
			cin >> temp;
			matrix.push_back( temp );
		}
		memset( matVisited, 0 , 21 * 21 * sizeof( matVisited[0][0] ) );
		finalResult.push_back( isSquarePresent( matrix ) );
	}//for( k );
	
	for( unsigned k = 0; k < finalResult.size(); ++k ) {
		if( finalResult[k] )
			cout<<"Case #"<<k+1<<": "<<"YES"<<endl;
		else
			cout<<"Case #"<<k+1<<": "<<"NO"<<endl;
	}
	return 0;
}