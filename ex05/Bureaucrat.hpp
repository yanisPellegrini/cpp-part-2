#include <string>

class Bureaucrat
{
	private:
		std::string _grade;
		std::string _name;
	public:
	Bureaucrat();
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
	Bureaucrat &operator<<(const Bureaucrat& other);
	std::string GetName() const;
	std::string GetGrade() const;
};
