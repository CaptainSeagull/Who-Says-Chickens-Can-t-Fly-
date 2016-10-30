#pragma once

	// Holds data about the player's shooting
	struct ShootingData {
		bool canShoot = true;
		float shotTimer = 0.0f;
		float maxTimer = 0.0f;
	};