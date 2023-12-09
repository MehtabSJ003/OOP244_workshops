/*
Name - MEHTAB SINGH JAGDE
Student ID - 119003226
Email - mjagde@myseneca.ca
Section - ZBB
Date- 06/10/2023

I have completed all my assignments myself respecting the academic integrity.

*/
#ifndef SDDS_LABEL_H_
#define SDDS_LABEL_H_
namespace sdds {
	class Label {
		//1 for the null terminator
		char m_frame[8+1];
		char* m_content;
	public:
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label();
		std::istream& readLabel(std::istream& istr = std::cin);
		std::ostream& printLabel(std::ostream& ostr = std::cout) const;
		Label& text(const char* content);
	};
}
#endif