#include <iostream>

int main()
{
	int mass[10], l, m, e;
	int arr_length = std::size(mass);
	int i;
	for (i = 0; i < arr_length; i++)
	{
		std::cout << "mass[" << i << "]="; std::cin >> mass[i];
	}
	_asm
	{
		mov ebx, 0; <0
		mov eax, 0; zero
		mov edx, 0; >0
		mov esi, 0;
		mov ecx, arr_length; 
		cycle: 
			cmp mass[esi], 0
			jg positive
			jl negative
			inc eax
			jmp nxt
				positive:
					inc edx
					jmp nxt
				negative:
					inc ebx
					jmp nxt
			nxt:
				add esi, 4;
		loop cycle
		mov l, ebx
		mov m, edx
		mov e, eax
	}
	std::cout << "\nlower zero=" << l << "\nmore zero=" << m << "\nzero=" << e;
}