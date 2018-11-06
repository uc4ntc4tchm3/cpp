#include <string>
#include <iterator>
#include <vector>

/*string split format*/

template<typename Out>
void split(const std::string &s, char delim, Out result) {
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}

/*
 *	how to use split format
 *	
 *	step1. read line from file 
 *	vector<string> readline;
 *	string buffer;
 *	while(getline(inputstream, buffer)){
 *		readline.push_back(buffer);
 *	}
 *	
 *	step 2. split data to each tokens
 *	for each(string buffer in readline){
 *		vector<string> splitData = split(buffer, ',');  // ',' is a token
 *	
 *	ex) buffer = "apple,banana,kiwi,pineapple";
 *		splitData = ["apple", "banana", "kiwi", "pineapple"];	
 *
 *
 */


/*
 *
 *	using file system
 *	
 *	read from file
 *	ifstream inputstream;
 *	inputstream.open(filename, options);
 *	...
 *
 *	write to file
 *	ofstream outputstream;
 *	outputstream.open(filename, options);
 *	...
 *
 *
 */