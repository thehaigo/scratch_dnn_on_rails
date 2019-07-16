# -*- encoding: utf-8 -*-
# stub: red-datasets 0.0.8 ruby lib

Gem::Specification.new do |s|
  s.name = "red-datasets".freeze
  s.version = "0.0.8"

  s.required_rubygems_version = Gem::Requirement.new(">= 0".freeze) if s.respond_to? :required_rubygems_version=
  s.require_paths = ["lib".freeze]
  s.authors = ["tomisuker".freeze, "Kouhei Sutou".freeze]
  s.date = "2019-03-24"
  s.description = "You can use datasets easily because you can access each dataset with multiple ways such as `#each` and Apache Arrow Record Batch.\n".freeze
  s.email = ["tomisuker16@gmail.com".freeze, "kou@clear-code.com".freeze]
  s.homepage = "https://github.com/red-data-tools/red-datasets".freeze
  s.licenses = ["MIT".freeze]
  s.rubygems_version = "2.7.6".freeze
  s.summary = "Red Datasets provides classes that provide common datasets such as iris dataset.".freeze

  s.installed_by_version = "2.7.6" if s.respond_to? :installed_by_version

  if s.respond_to? :specification_version then
    s.specification_version = 4

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
      s.add_runtime_dependency(%q<csv>.freeze, [">= 3.0.5"])
      s.add_runtime_dependency(%q<rubyzip>.freeze, [">= 0"])
      s.add_development_dependency(%q<bundler>.freeze, [">= 0"])
      s.add_development_dependency(%q<rake>.freeze, [">= 0"])
      s.add_development_dependency(%q<test-unit>.freeze, [">= 0"])
      s.add_development_dependency(%q<yard>.freeze, [">= 0"])
      s.add_development_dependency(%q<kramdown>.freeze, [">= 0"])
    else
      s.add_dependency(%q<csv>.freeze, [">= 3.0.5"])
      s.add_dependency(%q<rubyzip>.freeze, [">= 0"])
      s.add_dependency(%q<bundler>.freeze, [">= 0"])
      s.add_dependency(%q<rake>.freeze, [">= 0"])
      s.add_dependency(%q<test-unit>.freeze, [">= 0"])
      s.add_dependency(%q<yard>.freeze, [">= 0"])
      s.add_dependency(%q<kramdown>.freeze, [">= 0"])
    end
  else
    s.add_dependency(%q<csv>.freeze, [">= 3.0.5"])
    s.add_dependency(%q<rubyzip>.freeze, [">= 0"])
    s.add_dependency(%q<bundler>.freeze, [">= 0"])
    s.add_dependency(%q<rake>.freeze, [">= 0"])
    s.add_dependency(%q<test-unit>.freeze, [">= 0"])
    s.add_dependency(%q<yard>.freeze, [">= 0"])
    s.add_dependency(%q<kramdown>.freeze, [">= 0"])
  end
end
