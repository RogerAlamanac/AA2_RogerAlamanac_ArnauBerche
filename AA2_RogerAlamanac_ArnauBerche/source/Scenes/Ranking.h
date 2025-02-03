#pragma once
#include "Scene.h"
#include "../Object/TextObject.h"
#include <map>
#include <string>
class Ranking : public Scene {
private:
	TextObject* title;
	TextObject* space;
	std::map<std::string, int> spaceHighscores;

	TextObject* tank;
	std::map<std::string, int> tankHighscores;

	TextObject* splat;
	std::map<std::string, int> splatHighscores;

public:
    //void SaveRanking(const std::vector<Player>& ranking, const std::string& filename) {
    //    std::ofstream file(filename, std::ios::binary | std::ios::out);
    //    if (file.is_open()) {
    //        for (const auto& player : ranking) {
    //            file.write(reinterpret_cast<const char*>(&player), sizeof(Player));
    //        }
    //        file.close();
    //    }
    //    else {
    //        std::cerr << "Error al abrir el archivo para escritura" << std::endl;
    //    }
    //}

    //// Carga el ranking desde un archivo binario
    //std::vector<Player> LoadRanking(const std::string& filename) {
    //    std::vector<Player> ranking;
    //    std::ifstream file(filename, std::ios::binary | std::ios::in);
    //    if (file.is_open()) {
    //        Player player;
    //        while (file.read(reinterpret_cast<char*>(&player), sizeof(Player))) {
    //            ranking.push_back(player);
    //        }
    //        file.close();
    //    }
    //    return ranking;
    //}

    //// Muestra el ranking en consola
    //void displayRanking(const std::vector<Player>& ranking) {
    //    std::cout << "\nRanking de jugadores:" << std::endl;
    //    for (size_t i = 0; i < ranking.size(); ++i) {
    //        std::cout << i + 1 << ". " << ranking[i].name << " - " << ranking[i].score << " puntos" << std::endl;
    //    }
    //}

    //// Agrega un nuevo jugador al ranking, lo ordena y mantiene solo las 10 mejores puntuaciones
    //void addPlayerToRanking(std::vector<Player>& ranking, const std::string& name, int score) {
    //    Player newPlayer;
    //    strncpy(newPlayer.name, name.c_str(), sizeof(newPlayer.name) - 1);
    //    newPlayer.name[sizeof(newPlayer.name) - 1] = '\0';
    //    newPlayer.score = score;

    //    ranking.push_back(newPlayer);
    //    std::sort(ranking.begin(), ranking.end(), [](const Player& a, const Player& b) {
    //        return a.score > b.score; // Ordenar de mayor a menor puntuaci�n
    //        });

    //    if (ranking.size() > 10) {
    //        ranking.resize(10); // Mantener solo las 10 mejores puntuaciones
    //    }
    //}
	Ranking() = default;
	void OnEnter() override;
	void OnExit() override;
	void Update() override;
	void Render() override;
};