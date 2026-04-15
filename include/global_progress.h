#ifndef GLOBAL_PROGRESS_H
#define GLOBAL_PROGRESS_H
// 五十个太阳碎片
// 十二个羽毛
// 八个守护神
constexpr unsigned SUN_FRAGMENT_MAX = 50;
constexpr unsigned FEATHER_MAX = 12;
constexpr unsigned GOD_BONE_MAX = 8;
class GlobalProgress
{
private:
	unsigned m_sun_fragment;
	unsigned m_feather;
	unsigned m_god_bone;

public:
	void AddSunFragment()
	{
		++m_sun_fragment;
	}
	void AddFeather()
	{
		++m_feather;
	}
	void AddGodBone()
	{
		++m_god_bone;
	}
	bool SunFragmentEnough()
	{
		return m_sun_fragment == SUN_FRAGMENT_MAX;
	}
	bool FeatherEnough()
	{
		return m_feather == FEATHER_MAX;
	}
	bool GodBoneEnough()
	{
		return m_god_bone == GOD_BONE_MAX;
	}
	bool AllEnough()
	{
		return m_sun_fragment == SUN_FRAGMENT_MAX && m_feather == FEATHER_MAX && m_god_bone == GOD_BONE_MAX;
	}
};
#endif