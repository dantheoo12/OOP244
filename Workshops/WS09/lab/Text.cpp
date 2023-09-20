#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <cstring>
#include "Text.h"

using namespace std;

namespace sdds {
    int Text::getFileLength() const {
        int len = 0;
        ifstream fin(m_filename);
        while (fin) {
            fin.get();
            len += !!fin;
        }
        return len;
    }
    const char& Text::operator[](int index)const {
        return m_content[index];
    }
    // parameterized constructor
    Text::Text(const char* filename) {
        m_filename = nullptr;
        m_content = nullptr;
        if (filename != nullptr) {
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename, filename);
        }
        read();
    }
    // copy constructor
    Text::Text(const Text& src) {
        m_filename = nullptr;
        m_content = nullptr;
        *this = src;
    }
    // copy assignment operator
    Text& Text::operator=(const Text& src) {
        if (this != &src) {
            // copy filename
            if (m_filename != nullptr) {
                delete[] m_filename;
                m_filename = nullptr;
            }
            if (src.m_filename != nullptr) {
                m_filename = new char[strlen(src.m_filename) + 1];
                strcpy(m_filename, src.m_filename);
            }
            // copy content
            if (m_content != nullptr) {
                delete[] m_content;
                m_content = nullptr;
            }
            if (src.m_content != nullptr) {
                m_content = new char[strlen(src.m_content) + 1];
                strcpy(m_content, src.m_content);
            }
        }
        return *this;
    }
    // destructor
    Text::~Text() {
        delete[] m_filename;
        delete[] m_content;
        m_filename = nullptr;
        m_content = nullptr;
    }
    void Text::read() {
        if (m_filename != nullptr) {
            int fileLength = getFileLength();
            m_content = new char[fileLength + 1];
            ifstream fin(m_filename);
            for (int i = 0; i < fileLength; i++) {
                m_content[i] = fin.get();
            }
            // in case file is not null terminated, manually add a null terminator
            m_content[fileLength] = '\0';
            fin.close();
        }
    }
    void Text::write(std::ostream& os)const {
        if (m_content != nullptr) {
            os << m_content;
        }
    }
    std::ostream& operator<<(std::ostream& os, const Text& rhs) {
        rhs.write(os);
        return os;
    }
}