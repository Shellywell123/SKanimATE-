#include <iostream>
#include <vector>

// functions taken from online to replicate numpy features

//template<typename T>
std::vector<double> linspace(double start_in, double end_in, int num_in)
{

  std::vector<double> linspaced;

  double start = static_cast<double>(start_in);
  double end = static_cast<double>(end_in);
  double num = static_cast<double>(num_in);

  if (num == 0) { return linspaced; }
  if (num == 1) 
    {
      linspaced.push_back(start);
      return linspaced;
    }

  double delta = (end - start) / (num - 1);

  for(int i=0; i < num-1; ++i)
    {
      linspaced.push_back(start + delta * i);
    }
  linspaced.push_back(end); // I want to ensure that start and end
                            // are exactly the same as the input
  return linspaced;
}

//template <typename T>
std::vector<double> concat(std::vector<double> a, const std::vector<double>& b)
{
    a.reserve(a.size() + b.size());
    a.insert(a.end(), b.begin(), b.end());

    return a;
}