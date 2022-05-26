#include <iostream>

typedef std::string s;

int main()
{
	s array[5];
	while (array[0] != "sim" && array[0] != "nao") {
		system("cls");
		std::cout << "\033[1;34m Voce ja tem instalado git em seu computador ? (sim) ou (nao)" << std::endl;
		std::cin >> array[0];
	}

	if (array[0] == "nao") {
		system("winget install --id Git.Git -e --source winget");
	}

	while (array[1] != "sim" && array[1] != "nao") {
		system("cls");
		std::cout << "\033[1;34m Voce ja tem instalado o vcpkg em seu computador ? (sim) ou (nao)" << std::endl;
		std::cin >> array[1];
	}

	if (array[1] == "nao") {
		system("cls");
		std::cout << "\033[1;31m =====================================" <<
			"Instalando vcpkg e configurando!." <<
			"=====================================" << std::endl;
		system("cd c:/ && git clone https://github.com/Microsoft/vcpkg && cd vcpkg && bootstrap-vcpkg.bat && vcpkg integrate install");
		array[2] = "c:/";

	}
	else {

		if (array[2] != "c:/") {
			system("cls");
			std::cout << "Digite o local em que o vcpkg foi instalado" << std::endl;
			std::cin >> array[2];
		}

		while (array[3] != "tfs" && array[3] != "otc") {
			system("cls");
			std::cout << "\033[1;34m Digite qual projeto você quer instalar as biblioteca (tfs) ou (otc)" << std::endl;
			std::cin >> array[3];
		}

		if (array[3] == "tfs") {
			while (array[4] != "x64" && array[4] != "x32") {
				system("cls");
				std::cout << "\033[1;34m Digite em qual arquirtetura você deseja instalar (x64) ou (x32)" << std::endl;
				std::cin >> array[4];
			}
			if (array[4] == "x64") {
				system("cls");
				std::cout << "\033[1;31m =====================================" <<
					"Instalando as biblioteca!." <<
					"=====================================" << std::endl;
				array[2] = "cd " + array[2] + " && cd vcpkg && vcpkg install --triplet x64-windows boost-iostreams boost-asio boost-system boost-filesystem boost-variant boost-lockfree luajit libmariadb pugixml cryptopp fmt";
				system(array[2].c_str());
			}
			else if (array[4] == "x32") {
				system("cls");
				std::cout << "\033[1;31m =====================================" <<
					"Instalando as biblioteca!." <<
					"=====================================" << std::endl;
				array[2] = "cd " + array[2] + " && cd vcpkg && vcpkg install boost-iostreams boost-asio boost-system boost-filesystem boost-variant boost-lockfree luajit libmariadb pugixml cryptopp fmt";
				system(array[2].c_str());
			}
		}
		else if (array[3] == "otc") {
			while (array[4] != "x64" && array[4] != "x32") {
				system("cls");
				std::cout << "Digite em qual arquirtetura você deseja instalar (x64) ou (x32)" << std::endl;
				std::cin >> array[4];
			}

			if (array[4] == "x64") {
				system("cls");
				std::cout << "\033[1;31m =====================================" <<
					"Instalando as biblioteca!." <<
					"=====================================" << std::endl;
				array[2] = "cd " + array[2] + " && cd vcpkg && vcpkg install asio:x64-windows luajit:x64-windows glew:x64-windows physfs:x64-windows openal-soft:x64-windows libogg:x64-windows libvorbis:x64-windows zlib:x64-windows opengl:x64-windows nlohmann-json:x64-windows liblzma:x64-windows protobuf:x64-windows openssl:x64-windows";
				system(array[2].c_str());
			}
			else if (array[4] == "x32") {
				system("cls");
				std::cout << "\033[1;31m =====================================" <<
					"Instalando as biblioteca!." <<
					"=====================================" << std::endl;
				array[2] = "cd " + array[2] + " && cd vcpkg && vcpkg install asio:x86-windows luajit:x86-windows glew:x86-windows physfs:x86-windows openal-soft:x86-windows libogg:x86-windows libvorbis:x86-windows zlib:x86-windows opengl:x86-windows nlohmann-json:x86-windows liblzma:x86-windows protobuf:x86-windows openssl:x86-windows && vcpkg install --triplet x86-windows-static asio luajit glew physfs openal-soft libogg libvorbis zlib opengl nlohmann-json liblzma protobuf openssl";
				system(array[2].c_str());
			}
		}

		system("cls");
		std::cout << "\033[1;32m =====================================" <<
			"Tudo pronto!." <<
			"=====================================" << std::endl;
		system("pause");
	}

	return 0;
}