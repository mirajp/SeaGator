/* Does the word completion portion of the keyboard */

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <ctime>
#include <algorithm>

class Node {
	public:
	std::map<char,Node> children; //map character to child
	bool is_word;	//flag for complete word
	Node();
	void add(std::string to_add);
	std::vector<std::string> dfs(std::string agg);
	std::vector<std::string> search(std::string prefix, std::string agg="");
};

Node::Node() {
	this->is_word = false;
}

void Node::add(std::string to_add) {
	//std::cout << "Adding word: "<<to_add << "\n";
	if (to_add.length() == 0) {
		this -> is_word = true;
		return;
	}
	char key = to_add[0];
	to_add.erase(0,1); //remove the first character
	//std::cout<< "Ma key " << key << "\n";
	//std::cout << "Ma string " << to_add << "\n";
	if (this->children.count(key) > 0) {
		//std::cout << "Inside IF " << key << "\n";
		return(this->children[key].add(to_add));	
	} else {
		Node node;
		//std::cout << "In Else " << key << "\n";
		this->children[key] = node;
		return(this->children[key].add(to_add));	
	}
}

std::vector<std::string> Node::dfs(std::string agg) {
	std::vector<std::string> words;
	if (this->children.size() == 0) {  //if leaf
		words.push_back(agg);
		return words;
	}

	if (this->is_word == true) {
		words.push_back(agg);
	}
	for (std::map<char,Node>::iterator it = this->children.begin(); it != this->children.end(); ++it) {
		char key = it->first;
		return(this->children[key].dfs(agg+key));
	}
}

std::vector<std::string> Node::search(std::string prefix,std::string agg) {
	std::vector<std::string> words,words2,words3;
	if (prefix.length() > 0) {
		char key = prefix[0];
		prefix.erase(0,1);
		if (this->children.count(key)) { 
			agg += key;
			return(this->children[key].search(prefix,agg));
		} else {
			;
		}
	} else {
		if (this->is_word == true) {
			words.push_back(agg);
		}
		for (std::map<char,Node>::iterator it = this->children.begin(); it != this->children.end(); ++it) {
			char key = it->first;//first is key, second is value
			words2 = this->children[key].dfs(agg+key);
			words3.insert(words3.end(),words2.begin(),words2.end());
		}		
		words.insert(words.end(),words3.begin(),words3.end());
		return words;
	}
}

Node load_corpus() {
	std::ifstream corpus("test.txt");
	std::string line;
	Node root;
	if (corpus.is_open()) {
		while (std::getline(corpus,line)) {
			root.add(line);	
		}
	}
	return root;
}

int main() {

	std::clock_t start,end;
	start = std::clock();
	Node root = load_corpus();
	end = std::clock();
	std::cout << "Time: " << (end-start)/(double)(CLOCKS_PER_SEC/1000) << "\n";
	std::string a;
	std::cout << "Enter a prefix: ";
	std::getline(std::cin,a);
	int num_words = root.search(a).size();
	for(int i = 0; i < num_words; i++) {
		std::cout << root.search(a)[i] << std::endl;
	
	}
}
