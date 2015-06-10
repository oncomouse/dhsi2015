# Print 100 Haiku; Become Cool

three_syllables = [
	"the bottle","a drainpipe","small blue bits","a crow caws", "a dog shakes", "ferris wheels", "monkey bars", "stained table cloths", "three more shots", "tear-stained face", "salted pork", "luminous", "underwear", "haunted moon", "cold, dark house", "blood stained face", "eyes glisten", "haunted dreams", "lost, broken", "in the yard", "mocking bird", "wishing star", "shining sun", "glowing moon", "on my knees", "a blown kiss", "in my heart", "on my toes", "with all hope", "rain buckets", "on this day", "in her eyes", "in our hearts", "will stay strong", "unbelieved", "remorseful", "when i died", "in the trees", "beneath sky", "in my room", "leaving home", "hardest part", "whispers fade", "on stained sheets", "drunken thoughts", "sand grains fall", "on my tongue", "in my ears", "lay down now", "continues", "lucid dreams", "lost highway", "robins call", "worried glance", "in a stream", "menacing","ironic","messages","torn paper","heaven and hell","snowflakes fall","now in bloom","my old home"
]

two_syllables = [
	"thunder","solvent","lost cause","muddle","mumbles","mutters","thoughtless","driven","stalwart","flinches","finches","finger","fingers","midnight","madness","hunger","vital","alive","now dead","dreaming","swingset","heartless","grinning","new age","feelings","whimpers","arrows","struck down","lifeless","songbird","singing","burning","aching","soulful","angels","reason","deeper","harder","calling","heaven","gray clouds","lightning","lamplight","stunning","on snow", "in dreams", "under", "willows", "now blessed", "now lost", "sadness", "today", "never", "always", "bereft", "untold", "to me", "my thoughts", "my eyes", "in bloom", "lost soul", "again", "forlorn", "risen", "rise up", "children", "wonder", "feathers", "not down", "away", "too soft", "softer", "soft still", "wounded", "for love", "for hope", "with joy", "with pain", "panic", "nine lives", "heartfelt", "trouble", "too soon", "gone now", "and I", "I think", "safely", "flutters", "wanders", "your lips", "your eyes", "your smile", "comforts", "weighs down", "upon", "learning", "the sky", "the sea", "rivers", "we met", "eyes met", "like rain", "silent"
]

four_syllables = [
	"bitterest fog", "hard-pressed and strong", "willowy hair", "standing still silent", "the clouds reveal", "the wind takes words", "under blessed skies", "a sparrow weeps", "a hummingbird", "wet noodles steam", "steaming mud waits", "broken hearts beat", "lost memories", "shadows silent", "dust specks gather", "spiders spin webs", "ants signal code", "the river sleeps", "traffic moves slow", "rain on rooftops", "lost in silence", "long lost dreams gone", "a park bench calls", "streets full of rain", "pails of tears spill", "a glass of wine", "these days i think", "witness the lack", "can it begin?", "pull out my eyes", "ending begins", "planted in soil", "a wolf calls out", "darting salmon", "laundry hangs dry", "roaches scuttle","tiny fractures","a roiling stream","as sparrows sing","the last ash falls","rusted leaves fall","scars slow to heal","complicated"
]

(1..100).each do |x|
	puts three_syllables.sample + " " + two_syllables.sample
	puts four_syllables.sample + " " + three_syllables.sample
	puts three_syllables.sample + " " + two_syllables.sample
	puts ""
end
