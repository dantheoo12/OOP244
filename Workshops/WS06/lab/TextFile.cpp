#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {
   Line::operator const char* () const {
      return (const char*)m_value;
   }
   Line& Line::operator=(const char* lineValue) {
      delete[] m_value;
      m_value = new char[strLen(lineValue) + 1];
      strcpy(m_value, lineValue);
      return *this;
   }
   Line::~Line() {
      delete[] m_value;
   }
   void TextFile::setEmpty() {
        delete[] m_textLines;
        m_textLines = nullptr;
        delete[] m_filename;
        m_filename = nullptr;
        m_noOfLines = 0;
        m_pageSize = 0;
   }
   void TextFile::setFilename(const char* fname, bool isCopy) {
       // dynamically allocate m_filename, copy fname with prefix 'C_'
       if (isCopy) {
           m_filename = new char[strlen(fname) + 3];
           strcpy(m_filename, "C_");
           strcat(m_filename,fname);
       }
       // dynamically allocate m_filename, copy fname 
       else {
           m_filename = new char[strlen(fname) + 1];
           strcpy(m_filename, fname);
       }
   }
   void TextFile::setNoOfLines() {
       ifstream f(m_filename);
       if (f.is_open()) { 
           char current = '\0';
           while (f.get(current)) {
               if (current == '\n') {
                   ++m_noOfLines;
               }
           }
           ++m_noOfLines;
           f.close();
       }
       if (m_noOfLines == 0) {
           setEmpty();
       }
   }
   void TextFile::loadText() {
       if (*this) {
           ifstream f(m_filename);
           unsigned i = 0;
           string line;

           // delete first to prevent memory leak
           delete[] m_textLines;
           m_textLines = nullptr;
           // dynamically size m_textLines to m_noOfLines
           m_textLines = new Line[m_noOfLines];
           for (i = 0; i < m_noOfLines; i++) {
               if (getline(f, line)) {
                   m_textLines[i] = line.c_str();
               }
           }
           f.close();
       }
   }
   void TextFile::saveAs(const char* fileName)const {
       ofstream f(fileName);
       unsigned i = 0;
       if (f.is_open()) {
           for (i = 0; i < m_noOfLines; i++) {
               f << m_textLines[i] << '\n';
           }
           f.close();
       }
   }
   TextFile::TextFile(unsigned pageSize) {
       setEmpty();
       m_pageSize = pageSize;
   }
   TextFile::TextFile(const char* filename, unsigned pageSize) {
       setEmpty();
       m_pageSize = pageSize;
       if (filename) {
            setFilename(filename);
            setNoOfLines();
            loadText();
       }
   }
   TextFile::TextFile(const TextFile& src) {
       // initialize new resource variables in temp objects so that they can be deleted with setEmpty()
       m_textLines = new Line[src.m_noOfLines];
       m_filename = new char[strlen(src.m_filename) + 1];
       setEmpty();
       m_pageSize = src.m_pageSize;
       if (src) {
           setFilename(src.m_filename, true);
           src.saveAs(m_filename);
           m_noOfLines = src.m_noOfLines;
           loadText();
       }
   }
   TextFile& TextFile::operator=(const TextFile& src) {
       if (*this && src) {
           delete[] m_textLines;
           m_textLines = nullptr;
           src.saveAs(m_filename);
           m_noOfLines = src.m_noOfLines;
           loadText();
       }
       return *this;
   }
   TextFile::~TextFile() {
       delete[] m_textLines;
       m_textLines = nullptr;
       delete[] m_filename;
       m_filename = nullptr;
   }
   unsigned TextFile::lines()const {
       return m_noOfLines;
   }
   const char* TextFile::name()const {
       return m_filename;
   }
   std::ostream& TextFile::view(std::ostream& ostr)const {
       if (*this) {
           unsigned i = 0;
           // write filename
           ostr << m_filename << endl;
           // underline with '='
           for (i = 0; i < strlen(m_filename); i++) {
               ostr << '=';
           }
           ostr << endl;
           // write lines
           for (i = 0; i < m_noOfLines; i++) {
               ostr << m_textLines[i] << endl;
               if ((i + 1) % m_pageSize == 0) {
                   ostr << "Hit ENTER to continue...";
                   cin.ignore(1000, '\n'); // this works the first time and outputs a newline the second time
                   // cin.clear();???
                   // cout.flush()???
               }
           }
       }
       return ostr;
   }
   std::istream& TextFile::getFile(std::istream& istr) {
       string filename;
       istr >> filename;
       istr.ignore(1000, '\n');
       setFilename(filename.c_str());
       if (*this) {
           setNoOfLines();
           loadText();
       }
       return istr;
   }
   const char* TextFile::operator[](unsigned index)const {
       if (*this) {
           return (m_textLines[index % m_noOfLines]);
       }
       return nullptr;
   }
   TextFile::operator bool()const {
       return (m_filename != nullptr);
   }
   ostream& operator<<(ostream& ostr, const TextFile& text) {
       return (text.view(ostr));
   }
   std::istream& operator>>(istream& istr, TextFile& text) {
       return (text.getFile(istr));
   }

}