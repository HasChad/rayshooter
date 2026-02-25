#pragma once

#include "raylib.h"
#include <vector>
class ParticleEffect {
  public:
    Vector2 pos = { 0, 0 };
    Texture2D texture;
    float lifeTime = 1;

    void updateLife() { lifeTime -= GetFrameTime(); }

    void draw() const {
        DrawTextureRec(
            texture,
            (Rectangle){ 0, 0, (float)texture.width, (float)texture.height },
            { static_cast<float>(pos.x - texture.width / 2.0),
              static_cast<float>(pos.y - texture.height / 2.0) },
            WHITE
        );
    }

    static void updateAll();
    static void drawAll();
};

inline std::vector<ParticleEffect> particles;

inline void ParticleEffect::updateAll() {
    for (auto& particle : particles) {
        particle.updateLife();
    }

    for (int i = particles.size() - 1; i >= 0; i--) {
        if (particles[i].lifeTime < 0)
            particles.erase(particles.begin() + i);
    }
}

inline void ParticleEffect::drawAll() {
    for (auto& particle : particles) {
        particle.draw();
    }
}
