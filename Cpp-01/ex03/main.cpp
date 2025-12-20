#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club("crude spiked club	");

		HumanA bob("Bob", club);  // Weapon passed to constructor
		bob.attack();

		club.setType("some other type of club");  // Change weapon type
		bob.attack();  // Bob sees the change! (reference to same weapon)
	}

	{
		Weapon club("crude spiked club");
	
		HumanB jim("Jim");      // No weapon yet
		jim.attack();
		jim.setWeapon(club);    // Give weapon later
		jim.attack();
		club.setType("some other type of club");  // Change weapon type
		jim.attack();  // Jim sees the change! (pointer to same weapon)
	}

	return 0;
}

/*
 * KEY LESSON: When to use REFERENCE vs POINTER
 *
 * Use REFERENCE when:
 * - The object MUST exist (cannot be NULL)
 * - Must be set at construction time
 * - Will always refer to the same object
 * - Example: HumanA always has a weapon
 *
 * Use POINTER when:
 * - The object is OPTIONAL (can be NULL)
 * - Can be set/changed later
 * - May point to different objects over time
 * - Example: HumanB may or may not have a weapon
 *
 * WHY DOES CHANGING club AFFECT BOTH BOB AND JIM?
 * Because both use reference/pointer to the SAME weapon object!
 * They don't have a COPY - they have access to the ORIGINAL.
 */
