#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	print_subset(int *arr, int arr_size, int target)
{
	int	i;
	i = 0;
	
	while (i < arr_size)
	{
		printf("%d", arr[i]);
		if (i + 1 != arr_size)
			printf(" ");
		i++;
	}
	printf("\n");
}

void	ft_power_set(int *nums, int *arr, int target, int pos, int nums_size, int arr_size, int sum)
{
	int	i;
	i = pos;

	if (sum == target)
		print_subset(arr, arr_size, target);
	while (i < nums_size)
	{
		arr[arr_size] = nums[i];
		sum += arr[arr_size];
		arr_size++;
		ft_power_set(nums, arr, target, i + 1, nums_size, arr_size, sum);
		arr_size--;
		sum -= arr[arr_size];
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc <= 2)
		return (1);
	int	nums[argc - 2];
	int	arr[argc - 2];
	int	i = 2;
	while (argv[i])
	{
		nums[i - 2] = atoi(argv[i]);
		i++;
	}
	ft_power_set(nums, arr, atoi(argv[1]), 0, argc - 2, 0, 0);
	return (0);
}
