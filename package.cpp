//五十个太阳碎片
//十二个羽毛
//八个守护神
#include "package.h"
void Package::AddSunFragment() {
	++m_sun_fragment;
}
void Package::AddFeather() {
	++m_feather;
}
void Package::AddGodBone() {
	++m_god_bone;
}
bool Package::SunFragmentEnough() {
	return m_sun_fragment == SUN_FRAGMENT_MAX;
}
bool Package::FeatherEnough() {
	return m_feather == FEATHER_MAX;
}
bool Package::GodBoneEnough() {
	return m_god_bone == GOD_BONE_MAX;
}
bool Package::AllEnough() {
	return m_sun_fragment == SUN_FRAGMENT_MAX && m_feather == FEATHER_MAX && m_god_bone == GOD_BONE_MAX;
}