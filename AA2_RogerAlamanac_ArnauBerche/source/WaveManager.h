#pragma once 
#include "dep/inc/xml/rapidxml.hpp"
#include "dep/inc/xml/rapidxml_print.hpp"
#include "dep/inc/xml/rapidxml_utils.hpp"
#include "dep/inc/xml/rapidxml_iterators.hpp"

#include <vector>
#include <string>
#include <iostream>

struct EnemyConfig {
    int id;
    std::string pattern;
    int amount;
};

struct Wave {
    std::vector<EnemyConfig> enemies;
    EnemyConfig randomEnemy;
};

class WaveManager {
public:
    int currentWaveIndex = 0;
    std::vector<Wave> waves;
    bool HasNextWave() const {
        return currentWaveIndex < waves.size() - 1;
    }
    void LoadNextWave() {
        if (HasNextWave()) {
            currentWaveIndex++;
        }
    }
    std::vector<EnemyConfig>GetCurrentWaveEnemies() const {
        return waves[currentWaveIndex].enemies;
    }

    bool LoadFromXML(const std::string& filepath) {
        try {
            rapidxml::file<> xmlFile(filepath.c_str()); // Cargar el archivo
            rapidxml::xml_document<> doc;
            doc.parse<0>(xmlFile.data()); // Parsear el archivo

            auto* root = doc.first_node("level");
            if (!root) {
                std::cerr << "XML mal estructurado: Falta el nodo <level>\n";
                return false;
            }

            for (auto* waveNode = root->first_node("wave"); waveNode; waveNode = waveNode->next_sibling("wave")) {
                Wave wave;

                // Leer <random_enemy>
                auto* randomEnemyNode = waveNode->first_node("random_enemy");
                if (randomEnemyNode) {
                    wave.randomEnemy.id = std::stoi(randomEnemyNode->first_node("id")->value());
                    wave.randomEnemy.pattern = randomEnemyNode->first_node("pattern")->value();
                    wave.randomEnemy.amount = std::stoi(randomEnemyNode->first_node("amount")->value());
                }

                // Leer <enemy>
                for (auto* enemyNode = waveNode->first_node("enemy"); enemyNode; enemyNode = enemyNode->next_sibling("enemy")) {
                    EnemyConfig enemy;
                    enemy.id = std::stoi(enemyNode->first_node("id")->value());
                    enemy.pattern = enemyNode->first_node("pattern")->value();
                    enemy.amount = std::stoi(enemyNode->first_node("amount")->value());
                    wave.enemies.push_back(enemy);
                }

                waves.push_back(wave);
            }
            return true;
        }
        catch (const std::exception& e) {
            std::cerr << "Error al cargar el XML: " << e.what() << "\n";
            return false;
        }
    }

};