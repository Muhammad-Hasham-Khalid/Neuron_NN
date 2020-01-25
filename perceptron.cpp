#include <iostream>
#include <vector>

int main()
{
	float n(0.1), b(-0.2), w0(0.0), w1(0.0), ans(0);
	int xin[][2] = {{0,0}, {0,1}, {1,0}, {1,1}};
	std::vector<int> xans;

	xans.push_back(0), xans.push_back(0), xans.push_back(0), xans.push_back(1);

	std::vector<int> anslst;
	std::vector<float> delta_w[2];
	
	while(true)
	{
		for(int& i[2] : xin)
		{
			ans = w0*i[0] + w1*i[1] + b;
			if (ans < 0)
				ans = 0;
			anslst.push_back(ans);
		}
		if (anslst == xans)
			break;
	}
	for(int i=0; i<anslst.size();i++)
	{
		std::cout << anslst[i] << " ";
	}
	std::cin.get();
}
