#include "meteor.h"
#include "explosion.h"
#include <memory>

const float SPEED = 0.25f;
sf::FloatRect Meteor::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}
void Meteor::handleCollision(GameObject& otherGameObject)
{
	sf::Vector2f pos = sprite_.getPosition();
	float x = pos.x;
	float y = pos.y;
	if (otherGameObject.hasTag("laser"))
	{
		otherGameObject.makeDead();
	}
	makeDead();

	sf::FloatRect bounds = sprite_.getGlobalBounds();
	float laserX = x+(bounds.width /2.0f);
	float laserY = y+(bounds.height / 2.0f);
	ExplosionPtr explosion = std::make_shared<Explosion>(sf::Vector2f(laserX, laserY));
	GAME.getCurrentScene().addGameObject(explosion);
}
Meteor::Meteor(sf::Vector2f pos)
{
	setCollisionCheckEnabled(true);
	sprite_.setTexture(GAME.getTexture("Resources/meteor.png"));
	sprite_.setPosition(pos);
	assignTag("meteor");
}
void Meteor::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}
void Meteor::update(sf::Time& elapsed) {
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();
	if (pos.x < sprite_.getGlobalBounds().width * -1)
	{
		makeDead();
	}
	else
	{
		sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
	}
}