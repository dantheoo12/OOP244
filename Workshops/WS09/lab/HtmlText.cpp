#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "HtmlText.h"

namespace sdds {
	HtmlText::HtmlText(const char* filename, const char* title) : Text(filename) {
		m_title = nullptr;
		if (title != nullptr) {
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
		}
	}
	HtmlText::HtmlText(const HtmlText& src) {
		m_title = nullptr;
		*this = src;
	}
	HtmlText& HtmlText::operator=(const HtmlText& src) {
		if (this != &src) {
			Text::operator=(src);
			delete[] m_title;
			m_title = nullptr;
			if (src.m_title != nullptr) {
				m_title = new char[strlen(src.m_title) + 1];
				strcpy(m_title, src.m_title);
			}
		}
		return *this;
	}
	HtmlText::~HtmlText() {
		delete[] m_title;
	}
	void HtmlText::write(std::ostream& os)const {
		bool MS = false;
		int i = 0;
		os << "<html><head><title>";
		if (m_title != nullptr) {
			os << m_title;
		}
		else {
			os << "No title";
		}
		os << "</title></head>\n<body>\n";
		if (m_title != nullptr) {
			os << "<h1>" << m_title << "</h1>\n";
		}
		while ((*this)[i] != '\0') { // are the strings null terminated??
			char current = (*this)[i];
			if (current == ' ') {
				if (MS) {
					os << "&nbsp;";
				}
				else {
					MS = true;
					os << ' ';
				}
			}
			else if (current == '<') {
				os << "&lt;";
				MS = false;
			}
			else if (current == '>') {
				os << "&gt;";
				MS = false;
			}
			else if (current == '\n') {
				os << "<br />\n";
				MS = false;
			}
			else {
				os << current;
				MS = false;
			}
			i++;
		}
		os << "</body>\n</html>";
	}

}