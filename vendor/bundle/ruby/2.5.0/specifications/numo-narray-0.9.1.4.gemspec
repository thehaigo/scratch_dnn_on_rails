# -*- encoding: utf-8 -*-
# stub: numo-narray 0.9.1.4 ruby lib
# stub: ext/numo/narray/extconf.rb

Gem::Specification.new do |s|
  s.name = "numo-narray".freeze
  s.version = "0.9.1.4"

  s.required_rubygems_version = Gem::Requirement.new(">= 0".freeze) if s.respond_to? :required_rubygems_version=
  s.require_paths = ["lib".freeze]
  s.authors = ["Masahiro TANAKA".freeze]
  s.date = "2019-01-10"
  s.description = "Numo::NArray - New NArray class library in Ruby/Numo.".freeze
  s.email = ["masa16.tanaka@gmail.com".freeze]
  s.extensions = ["ext/numo/narray/extconf.rb".freeze]
  s.files = ["ext/numo/narray/extconf.rb".freeze]
  s.homepage = "https://github.com/ruby-numo/numo-narray".freeze
  s.licenses = ["BSD-3-Clause".freeze]
  s.required_ruby_version = Gem::Requirement.new("~> 2.1".freeze)
  s.rubygems_version = "2.7.6".freeze
  s.summary = "alpha release of Numo::NArray - New NArray class library in Ruby/Numo (NUmerical MOdule)".freeze

  s.installed_by_version = "2.7.6" if s.respond_to? :installed_by_version

  if s.respond_to? :specification_version then
    s.specification_version = 4

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
      s.add_development_dependency(%q<bundler>.freeze, [">= 0"])
      s.add_development_dependency(%q<rake>.freeze, [">= 0"])
      s.add_development_dependency(%q<test-unit>.freeze, [">= 0"])
      s.add_development_dependency(%q<rake-compiler>.freeze, [">= 1.0.1", "~> 1.0"])
      s.add_development_dependency(%q<rake-compiler-dock>.freeze, ["~> 0"])
    else
      s.add_dependency(%q<bundler>.freeze, [">= 0"])
      s.add_dependency(%q<rake>.freeze, [">= 0"])
      s.add_dependency(%q<test-unit>.freeze, [">= 0"])
      s.add_dependency(%q<rake-compiler>.freeze, [">= 1.0.1", "~> 1.0"])
      s.add_dependency(%q<rake-compiler-dock>.freeze, ["~> 0"])
    end
  else
    s.add_dependency(%q<bundler>.freeze, [">= 0"])
    s.add_dependency(%q<rake>.freeze, [">= 0"])
    s.add_dependency(%q<test-unit>.freeze, [">= 0"])
    s.add_dependency(%q<rake-compiler>.freeze, [">= 1.0.1", "~> 1.0"])
    s.add_dependency(%q<rake-compiler-dock>.freeze, ["~> 0"])
  end
end
