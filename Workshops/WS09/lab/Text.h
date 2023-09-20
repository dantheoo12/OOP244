#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
namespace sdds {
   class Text {
      char* m_filename;
      char* m_content;
      int getFileLength()const;
   protected:
      const char& operator[](int index)const;
   public:
      Text(const char* filename=nullptr);
      Text(const Text& src);
      Text& operator=(const Text& src);
      virtual ~Text();
      void read();
      virtual void write(std::ostream& os)const;

      friend std::ostream& operator<<(std::ostream& os, const Text& rhs);
   };
   std::ostream& operator<<(std::ostream& os, const Text& rhs);
}
#endif // !SDDS_PERSON_H__

