#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void showMenu(); // função para exibir o menu
void createFile(); // criar um novo arquivo
void editFile(); // editar um arquivo existente
void saveFile(const string& filename, const string& content); // salvar conteúdo em um arquivo


int main() {
	while (true) {
		showMenu();

		int choice;
		cout << "Escolha um opção: ";
		cin >> choice;
		cin.ignore(); // limpar o buffer de entrada

		switch (choice) {
		case 1:
			createFile();
			break;

		case 2:
			editFile();
			break;

		case 3:
			cout << "Encerrando o programa. Até mais!\n";
			return 0;

		default:
			cout << "Opção inválida. Tente novamente.\n";
		}
	}
	return 0;
}

void showMenu() {
	cout << "\n--- Editor de Texto Básico ---\n";
	cout << "1. Criar um novo arquivo\n";
	cout << "2. Editar um arquivo existente\n";
	cout << "3. Sair\n";
	cout << "----------------------------------\n";
}

void createFile() {
	string filename, content;
	cout << "Digite o nome do arquivo (Com extensão, ex: texto.txt): ";
	cin.ignore(); // ignorar o buffer restante
	getline(cin, filename);

	cout << "Digite o conteúdo do arquivo (digite 'FIM' em uma linha para terminar):\n";

	string line;
	while (true) {
		getline(cin, line);
		if (line == "FIM") break; // encerrar ao digitar "FIM"
		content += line + "\n"; // adicionar linha ao conteúdo
	}
	saveFile(filename, content);
}

void saveFile(const string& filename, const string& content) {
	ofstream file(filename); // abrir o arquivo para escrita
	if (file.is_open()) {
		file << content;
		file.close();
		cout << "Arquivo salvo com sucesso!\n";
	}
	else {
		cout << "Erro ao salvar o arquivo!\n";
	}
}

void editFile() {
	string filename, content;

	cout << "Digite o nome do arquivo a ser editado: ";
	cin.ignore();
	getline(cin, filename);

	ifstream file(filename); // abrir o arquivo para leitura
	if (file.is_open()) {
		cout << "Conteúdo atual do arquivo:\n";
		string line;
		while (getline(file, line)) {
			cout << line << endl;
			content += line + "\n"; // armazenar o conteúdo atual
		}
		file.close();

		cout << "\n Digite o novo conteúdo para o arquivo (digite 'FIM' para terminar): \n";

		string newLine;
		while (true) {
			getline(cin, newLine);
			if (newLine == "FIM") break;
			content += newLine + "\n";
		}
		saveFile(filename, content);
	}
	else {
		cout << "Erro ao abrir o arquivo. Verifique se o arquivo existe.\n";
	}
}
