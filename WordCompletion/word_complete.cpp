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
		this->children[key].add(to_add);	
	} else {
		Node node;
		this->children[key] = node;
		node.add(to_add);	
	}
}

std::vector<std::string> Node::dfs(std::string agg) {
	std::vector<std::string> words;
	std::cout << "in dfs" << "\n";
	if (this->children.size() == 0) {  //if leaf
		std::cout << agg << "\n";
		words.push_back(agg);
		std::cout << "size: "<<words.size() << "\n";
		return words;
	}

	if (this->is_word == true) {
		std::cout <<"is word " << agg << "\n";
		words.push_back(agg);
	}
	for (std::map<char,Node>::iterator it = this->children.begin(); it != this->children.end(); ++it) {
		char key = it->first;
		this->children[key].dfs(agg+key);
	}
}

std::vector<std::string> Node::search(std::string prefix,std::string agg) {
	std::vector<std::string> words,words2;
	std::cout << "in search\n";
	if (prefix.length() > 0) {
		std::cout << "prefix len " <<prefix.length() << "\n";
		char key = prefix[0];
		prefix.erase(0,1);
		if (this->children.count(key)) {
			agg += key;
			std::cout << "key: " << key << " agg: "<< agg << "\n";
			return (this->children[key].search(prefix,agg));
		} else {
			std::cout << "alone" << words.size() << "\n";
			return words;
		}
	} else {
		if (this->is_word == true) {
			std::cout << "is word " << agg << "\n";
			words.push_back(agg);
		}
		for (std::map<char,Node>::iterator it = this->children.begin(); it != this->children.end(); ++it) {
			char key = it->first;
			words2 = this->children[key].dfs(agg+key);
		}		
		words.insert(words.end(),words2.begin(),words2.end());
		std::cout <<"WTF " << words.size() << "\n";
		return words;
	}
}

Node load_corpus() {
	std::ifstream corpus("test.txt");
	std::string line;
	Node root;
	if (corpus.is_open()) {
		while (std::getline(corpus,line)) {
			//std::cout << line <<"\n";
			root.add(line);	
		}
	}
	
	
	for (std::map<char,Node>::iterator it = root.children.begin(); it != root.children.end(); ++it) {
		char key = it->first;
		std::cout << key << "\n";
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
	std::cout << root.search(a).front() << "\n";	
}
