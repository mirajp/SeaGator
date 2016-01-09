/* Does the word completion portion of the keyboard */

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <ctime>

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
	if (to_add.length() == 0) {
		this -> is_word = true;
		return;
	}
	char key = to_add[0];
	to_add.erase(0,1); //remove the first character
	if (this->children.count(key)) {
		return(this->children[key].add(to_add));	
	} else {
		Node node;
		this->children[key] = node;
		node.add(to_add);	
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
	std::vector<std::string> words,words2;
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
			char key = it->first;
			words2 = this->children[key].dfs(agg+key);
		}		
		words.insert(words.end(),words2.begin(),words2.end());
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
	std::cout << root.search(a).size() << "\n";	
}
