#pragma once
//五十个太阳碎片
//十二个羽毛
//八个守护神
constexpr unsigned SUN_FRAGMENT_MAX = 50;
constexpr unsigned FEATHER_MAX = 12;
constexpr unsigned GOD_BONE_MAX = 8;
class Package {
private:
	unsigned m_sun_fragment;
	unsigned m_feather;
	unsigned m_god_bone;
public:
	void AddSunFragment();
	void AddFeather();
	void AddGodBone();
	bool SunFragmentEnough();
	bool FeatherEnough();
	bool GodBoneEnough();
	bool AllEnough();
};