#include <vector>
#include <string>

using namespace std;

class MatriuSparse {
public:
	MatriuSparse();
	~MatriuSparse();

	MatriuSparse(const string &fichero);

private:
	std::vector<float> m_fil;
	std::vector<float> m_col;
	std::vector<float> m_val;
};