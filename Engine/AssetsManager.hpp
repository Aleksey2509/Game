#ifndef ENGINE_ASSETSMANAGER_HPP
#define ENGINE_ASSETSMANAGER_HPP

#include <unordered_map>
#include <string>

template <class T>
class AssetsManager
{
public:
	void Load(const std::string& name, const std::string& path)
	{
		assets_[name].loadFromFile(path);
	}
	T& Get(const std::string& name)
	{
		return assets_[name];
	}
private:
	std::unordered_map<std::string, T> assets_;
};

#endif //ENGINE_ASSETSMANAGER_HPP