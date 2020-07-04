#include<iostream>

using namespace std;

template<typename Tip>
int countUnique(Tip *array, int size)
{
	int countUniques = 0;
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		counter = 0;
		for (int j = 0; j < size; j++)
		{
			if (array[i] == array[j])
			{
				counter++;
			}
		}
		if (counter == 1)
		{
			countUniques++;
		}
	}
	return countUniques;
}

class Acceleration
{
private:
	double speed1, speed2, speed3;
public:
	Acceleration() : speed1(0), speed2(0), speed3(0) {}
	Acceleration(double s1, double s2, double s3) : speed1(s1), speed2(s2), speed3(s3) {}
	friend bool operator==(const Acceleration&, const Acceleration&);
};
bool operator==(const Acceleration& a1, const Acceleration& a2)
{
	return a1.speed1 == a2.speed1 && a1.speed2 == a2.speed2 && a1.speed3 == a2.speed3;
}

class Processor
{
	int mCoreCount;
	int mBaseOpsPerSecond;
	int mCurrentOpsPerSecond;
public:
	Processor() : mCoreCount(0), mBaseOpsPerSecond(0), mCurrentOpsPerSecond(0) {}
	Processor(int cores, int baseOps, int currOps) : mCoreCount(cores), mBaseOpsPerSecond(baseOps), mCurrentOpsPerSecond(currOps)
	{
		if ((mCoreCount % 2) != 0 || mCoreCount < 0)
		{
			cout << "Unvalid core number." << endl;
			mCoreCount = 2;
		}
		if (mBaseOpsPerSecond < 0)
		{
			mBaseOpsPerSecond *= -1;
		}
	}
	void boost()
	{
		mCurrentOpsPerSecond *= 1.1;
	}
	void restore()
	{
		mCurrentOpsPerSecond = mBaseOpsPerSecond;
	}
	double timeForImage(int n, int m, int opsPerPixel)
	{
		int totalOps = n * m * opsPerPixel;
		return (opsPerPixel / mCurrentOpsPerSecond) / 60;
	}
	friend double CalculateTimeSaved(Processor proc, int *array, int size);
};
double CalculateTimeSaved(Processor proc, int *array, int size)
{	
	int totalOps = 0;
	for (int i = 0; i < size; i++)
	{
		totalOps += array[i];
	}
	double time1 = totalOps / proc.mCurrentOpsPerSecond;
	proc.boost();
	double time2 = totalOps / proc.mCurrentOpsPerSecond;
	return time1 - time2;
}

int main()
{
	int array[] = { 2, 2, 5, 2, 4, 4 };
	cout << countUnique(array, 6) << endl;

	system("pause");
}