#include <iostream>

int main()
{
	// �о�� �����.
	char buffer[256];

	// ���� ��Ʈ�� ��ü ����.
	FILE* file = nullptr;

	// ���� ����.
	fopen_s(&file, "Test.txt", "rt");
	 
	// ���� ����.
	if (file != nullptr)
	{
		// ���ۿ� ���� �о���̱�.
		while (!feof(file))
		{
			//if (fgets(buffer, 256, file) == nullptr)
			//{
			//	break;
			//}
			fgets(buffer, 256, file);
			
			// ���.
			std::cout << buffer;
		}

		// ���� �ݱ�.
		// fclose(file);
	}
}