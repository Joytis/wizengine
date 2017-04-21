// INCLUDE THIS TEST
#include <boost/test/unit_test.hpp>

// Define our Module
#include "engine_includes.hpp"
#include "EntityManager.hpp"
#include "TextureManager.hpp"
#include "includes.hpp"

BOOST_AUTO_TEST_SUITE(EntityManagerTestSuite)

BOOST_AUTO_TEST_CASE(em_test0)
{
    EntityManager em;
    BOOST_CHECK(em.create_entity());
}

BOOST_AUTO_TEST_CASE( em_test1 ){

}

BOOST_AUTO_TEST_CASE( tm_construct_test ){
    TextureManager tm;
    BOOST_REQUIRE(tm.get_texture("boost") == nullptr);
}

// Tests the validity of the Texture Manager system.
BOOST_AUTO_TEST_CASE( tm_general_usage_test ){
    TextureManager tm;
	TextureComponent t0;

	SDL_Texture* texture1 = (SDL_Texture*)0x0000000056473626;
	t0.w = 100;
	t0.h = 200;
	t0.tex = texture1;

	TextureComponent t1;
	SDL_Texture* texture2 = (SDL_Texture*)0x0000000056473627;
	t0.w = 100;
	t0.h = 200;
	t0.tex = texture2;

	BOOST_REQUIRE(tm.add_texture("test1", &t0) == GENERIC_SUCCESS);
	BOOST_REQUIRE(tm.add_texture("test2", &t1) == GENERIC_SUCCESS);
	BOOST_REQUIRE(tm.add_texture("test1", &t0) == ERR_GENERIC_FAILED);

	TextureComponent* testcomp;
	testcomp = tm.get_texture("test1");
	BOOST_REQUIRE(testcomp == &t0);
	BOOST_REQUIRE(tm.get_texture("test2") == &t1);
	BOOST_REQUIRE(testcomp->tex == t0.tex);

	// Moved to Renderer test
	//============================================
	// BOOST_REQUIRE(tm.remove_texture("test1") == GENERIC_SUCCESS);
	// BOOST_REQUIRE(tm.remove_texture("test1") == ERR_GENERIC_FAILED);
	// BOOST_REQUIRE(tm.get_texture("test1") == nullptr);

	// tm.clear();
	// BOOST_REQUIRE(tm.get_texture("test2") == nullptr);
}

BOOST_AUTO_TEST_SUITE_END()

// EOF