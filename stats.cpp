#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int* histogram(int scores[], int count); 
double deviation(int scores[], int count);
double mean(int scores[], int count);

int main()
{
	const int MAX = 100;
	int scores[MAX];
	int score = 0;
	int count = 0;

	cout << "Please input your scores (-1 to stop): " << endl;
	cin >> score;

	while (score != -1)  
	{
		if (score >= 0)
		{
			scores[count++] = score;
			cin >> score;
		}
		else
		{
			cout << "Please input a value greater than zero: " << endl;
			cin >> score;
		}
	}



	int* bins = histogram(scores, count);

	for (int i = 9; i >= 0; i--)
	{
		cout << i << '|' << " ";
		for (int j = 0; j <= bins[i] - 1; j++)
		{
			cout << '*';
		}
		cout << endl;
	}

	cout << "SD: " << setprecision(6) << deviation(scores, count) << endl; 

	//system("pause");
	return 0;
}


int* histogram(int scores[], int count)
{
	static int bins[10];

	for (int i = 0; i < count; i++)
	{
		int num_scores = scores[i];

		if (num_scores >= 90 && num_scores < 110)
		{
			bins[9] += 1;
		}
		else if (num_scores >= 80 && num_scores < 90)
		{
			bins[8] += 1;
		}
		else if (num_scores >= 70 && num_scores < 80)
		{
			bins[7] += 1;
		}
		else if (num_scores >= 60 && num_scores < 70)
		{
			bins[6] += 1;
		}
		else if (num_scores >= 50 && num_scores < 60)
		{
			bins[5] += 1;
		}
		else if (num_scores >= 40 && num_scores < 50)
		{
			bins[4] += 1;
		}
		else if (num_scores >= 30 && num_scores < 40)
		{
			bins[3] += 1;
		}
		else if (num_scores >= 20 && num_scores < 30)
		{
			bins[2] += 1;
		}
		else if (num_scores >= 10 && num_scores < 20)
		{
			bins[1] += 1;
		}
		else
		{
			bins[0] += 1;
		}
	}
	return bins;
}


double deviation(int scores[], int count)
{
	double avg = mean(scores, count); 

	double sum = 0;
	for (int i = 0; i < count; i++)
	{
		sum += pow(scores[i] - avg, 2);
	}
	return sqrt(sum / count);
}


double mean(int scores[], int count)
{
	double sum = 0;
	for (int i = 0; i < count; i++)
	{
		sum += scores[i];
	}
	return sum / count; 
}