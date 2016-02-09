/* Does the word completion portion of the keyboard */

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <ctime>
#include <algorithm>

int line_number = 1;
std::map <std::string, int> wordRank;

class Node {
	public:
	std::map<char,Node *> children; //map character to child
	int line_num;
	bool is_word;	//flag for complete word
	Node();
	void add(std::string to_add);
	std::vector<std::string> dfs(std::string agg,std::vector<std::string> &words);
	std::vector<std::string> search(std::string prefix, std::string agg="");
};

Node::Node() {
	this->is_word = false;
	this->line_num = 0;
}

void Node::add(std::string to_add) {
	//std::cout << "Adding word: "<<to_add << "\n";
	if (to_add.length() == 0) {
		this -> is_word = true;
		this -> line_num = line_number;
		return;
	}
	char key = to_add[0];
	to_add.erase(0,1); //remove the first character
	//std::cout<< "Ma key " << key << "\n";
	//std::cout << "Ma string " << to_add << "\n";
	if (this->children.count(key) > 0) {
		//std::cout << "Inside IF " << key << "\n";
		return(this->children[key]->add(to_add));	
	} else {
		Node *node = new Node();
		//std::cout << "In Else " << key << "\n";
		this->children[key] = node;
		return(this->children[key]->add(to_add));	
	}
}

std::vector<std::string> Node::dfs(std::string agg,std::vector<std::string> &words) {
	//std::vector<std::string> words;
	//std::cout << "in dfs: " << agg << std::endl;
	if (this->is_word == true) {  // node is a word
		//std::cout << "in dfs: " << agg << std::endl;
		words.push_back(agg);
		return words;
	for (std::map<char,Node *>::iterator it = this->children.begin(); it != this->children.end(); ++it) {
		char key = it->first;
		return this->children[key]->dfs(agg+key,words);
	}
}

std::vector<std::string> Node::search(std::string prefix,std::string agg) {
	std::vector<std::string> words,words2,words3;
	if (prefix.length() > 0) {
		char key = prefix[0];
		prefix.erase(0,1);
		if (this->children.count(key)) { 
			agg += key;
			return(this->children[key]->search(prefix,agg));
		} 
	} else {
		if (this->is_word == true) {
			std::cout << "In search: " << agg <<std::endl;
			words.push_back(agg);
		}
		for (std::map<char,Node *>::iterator it = this->children.begin(); it != this->children.end(); ++it) {
			char key = it->first;//first is key, second is value
			words2 = this->children[key]->dfs(agg+key,words);
			for (int i = 0; i < words2.size(); i++) {
			//	std::cout << words2[i] << std::endl;
			}
			//words3.insert(words3.end(),words2.begin(),words2.end());
			for (int i = 0; i < words3.size(); i++) {
			//	std::cout << words3[i] << std::endl;
			}
		}		
		//words.insert(words.end(),words3.begin(),words3.end());
		return words;
	}
}

Node load_corpus() {
	std::ifstream corpus("test.txt");
	std::string line;
	Node root;
	if (corpus.is_open()) {
		while (std::getline(corpus,line)) {
			wordRank[line] = line_number;
			root.add(line);	
			line_number++;
		}
	}
	std::cout << root.children['t']->children['h']->children['a']->children.size() << std::endl;
	return root;
}

bool compareRanks(std::string word1, std::string word2) {
	return wordRank[word1] < wordRank[word2];	
}


int main() {

	std::clock_t start,end;
	start = std::clock();
	Node root = load_corpus();
	end = std::clock();
//	std::cout << "Time: " << (end-start)/(double)(CLOCKS_PER_SEC/1000) << "\n";
	std::string prefix;
	std::cout << "Enter a prefix: ";
	std::getline(std::cin,prefix);
	
	std::vector <std::string> suggestedWords = root.search(prefix);
	std::sort(suggestedWords.begin(),suggestedWords.end(),compareRanks);
	int num_words = suggestedWords.size();
	for(int i = 0; i < num_words; i++) {
		std::string suggestedWord = suggestedWords[i];
		std::cout << "Suggested: " << suggestedWord << ", #" << wordRank[suggestedWord] << std::endl;
		//std::cout << "Suggested: "<<root.search(prefix)[i] << std::endl;
	
	}
}
