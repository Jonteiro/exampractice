#include <stdio.h>
#include <stdlib.h>

void	print_subset(int *arr, int arr_size)
{
	int i;

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

void	find_subsets(int *nums, int *arr, int target, int pos, int nums_size, int arr_size, int sum)
{
	int i;

	if (sum == target)
		print_subset(arr, arr_size);
	i = pos;
	while (i < nums_size)
	{
		arr[arr_size] = nums[i];
		sum += arr[arr_size];
		arr_size++;
		find_subsets(nums, arr, target, i + 1, nums_size, arr_size, sum);
		arr_size--;
		sum -= arr[arr_size];
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	*nums;
	int	*arr;
	int	i;

	if (argc <= 2)
		return (1);
	nums = (int *)malloc(sizeof(int) * (argc - 2));
	arr = (int *)malloc(sizeof(int) * (argc - 2));
	if (!nums || !arr)
		return (1);
	i = 2;
	while (argv[i])
	{
		nums[i - 2] = atoi(argv[i]);
		i++;
	}
	find_subsets(nums, arr, atoi(argv[1]), 0, argc - 2, 0, 0);
	free(nums);
	free(arr);
	return (0);
}
