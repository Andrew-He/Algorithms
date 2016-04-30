#include <unordered_map>
#include <vector>
#include <cstddef>


namespace cache {

	template <typename key_t, typename value_t>
	class lru {
		typedef typename std::pair<key_t, value_t> pair; 
		typedef typename std::vector<pair>::iterator list_iterator; 
		
		std::vector<pair> cache_list; 
		std::unordered_map<key_t, list_iterator> cache_map; 
		size_t max_size; 

	public:
		lru(size_t max): max_size(max){}
		
		void put( const key_t &key, const value_t &value){
			auto it = cache_map.find(key);
			if (it != cache_map.end()) {
				cache_list.erase(it -> second ); 
				cache_map.erase(it); 
			}
			cache_list.push_front(pair(key, value));
			cache_map[key] = cache_list.begin(); 

			if (cache_map.size() > max_size)
			{
				auto last = cache_list.end(); 
				last--; 
				cache_map.erase( last -> first );
				cache_list.pop_back(); 
			}
		}

		const value_t &get(const key_t &key){
			auto it = cache_map.find(key); 
			if (it == cache_map.end()){
				throw std::range_error("no such key in cache"); 
			} else {
				cache_list.splice( cache_list.begin(), cache_list, it -> second); 
			}
		}
		bool exists(const key_t &key) const {
			return cache_map.find(key) != cache_map.end(); 
		}

		size_t size() const {
			return cache_map.size(); 
		}
	};
}




int main(){
	cache::lru<int, int> lr(10); 

}