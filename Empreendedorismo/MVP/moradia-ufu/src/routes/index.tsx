import { createFileRoute } from "@tanstack/react-router";
import { useState } from "react";
import {
  Home,
  Search,
  User,
  LayoutGrid,
  MessageSquare,
  MapPin,
  Wifi,
  Car,
  Sofa,
  CheckCircle2,
  Pencil,
  Pause,
  Plus,
  Send,
  GraduationCap,
} from "lucide-react";
import { Button } from "@/components/ui/button";
import { Input } from "@/components/ui/input";
import { Badge } from "@/components/ui/badge";
import { Card, CardContent } from "@/components/ui/card";
import { Checkbox } from "@/components/ui/checkbox";
import { Label } from "@/components/ui/label";
import { Slider } from "@/components/ui/slider";
import { Avatar, AvatarFallback, AvatarImage } from "@/components/ui/avatar";
import { Separator } from "@/components/ui/separator";

export const Route = createFileRoute("/")({
  head: () => ({
    meta: [
      { title: "Moradia UFU — Encontre sua moradia perto da UFU" },
      {
        name: "description",
        content:
          "Plataforma para estudantes encontrarem repúblicas, quartos e apartamentos próximos à UFU em Uberlândia.",
      },
    ],
  }),
  component: MoradiaUFU,
});

type View = "home" | "buscar" | "perfil" | "anuncios" | "mensagens";

const navItems: { id: View; label: string; icon: typeof Home }[] = [
  { id: "home", label: "Início", icon: Home },
  { id: "buscar", label: "Buscar", icon: Search },
  { id: "perfil", label: "Meu Perfil", icon: User },
  { id: "anuncios", label: "Meus Anúncios", icon: LayoutGrid },
  { id: "mensagens", label: "Mensagens", icon: MessageSquare },
];

const featured = [
  {
    title: "Quarto individual — República Santa Mônica",
    price: "R$ 850/mês",
    location: "Santa Mônica, 5 min da UFU",
    img: "https://images.unsplash.com/photo-1505691938895-1758d7feb511?w=600&q=70",
  },
  {
    title: "Apartamento mobiliado próximo Umuarama",
    price: "R$ 1.450/mês",
    location: "Umuarama, Uberlândia",
    img: "https://images.unsplash.com/photo-1502672260266-1c1ef2d93688?w=600&q=70",
  },
  {
    title: "Vaga compartilhada — Bairro Saraiva",
    price: "R$ 520/mês",
    location: "Saraiva, perto do Campus Glória",
    img: "https://images.unsplash.com/photo-1522708323590-d24dbb6b0267?w=600&q=70",
  },
];

const searchResults = [
  ...featured,
  {
    title: "República feminina — 4 vagas",
    price: "R$ 700/mês",
    location: "Santa Mônica",
    img: "https://images.unsplash.com/photo-1560448204-e02f11c3d0e2?w=600&q=70",
  },
  {
    title: "Studio mobiliado individual",
    price: "R$ 1.200/mês",
    location: "Centro, Uberlândia",
    img: "https://images.unsplash.com/photo-1493809842364-78817add7ffb?w=600&q=70",
  },
  {
    title: "Quarto em república mista",
    price: "R$ 600/mês",
    location: "Tibery",
    img: "https://images.unsplash.com/photo-1484154218962-a197022b5858?w=600&q=70",
  },
];

const myListings = [
  { title: "Quarto individual — República Santa Mônica", price: "R$ 850", status: "Ativo", views: 124 },
  { title: "Vaga compartilhada Bairro Saraiva", price: "R$ 520", status: "Ativo", views: 87 },
  { title: "Apartamento mobiliado Umuarama", price: "R$ 1.450", status: "Pausado", views: 56 },
];

const contacts = [
  { name: "Mariana Souza", last: "Oi! A vaga ainda está disponível?", time: "10:42", unread: 2 },
  { name: "João Pedro Lima", last: "Posso visitar amanhã?", time: "09:15", unread: 0 },
  { name: "Beatriz Almeida", last: "Obrigada pelas fotos!", time: "Ontem", unread: 0 },
  { name: "Rafael Mendes", last: "Aceita pets?", time: "Ontem", unread: 1 },
  { name: "Larissa Castro", last: "Combinado, até sábado.", time: "Seg", unread: 0 },
];

const conversation = [
  { from: "them", text: "Oi! Vi seu anúncio do quarto em Santa Mônica." },
  { from: "me", text: "Olá, Mariana! Sim, a vaga está disponível 😊" },
  { from: "them", text: "Que ótimo! Posso agendar uma visita essa semana?" },
  { from: "me", text: "Claro! Quinta às 18h funciona pra você?" },
  { from: "them", text: "Perfeito! Obrigada 🙏" },
];

function MoradiaUFU() {
  const [view, setView] = useState<View>("home");

  return (
    <div className="flex min-h-screen w-full bg-muted/30">
      {/* Sidebar */}
      <aside className="hidden md:flex w-64 flex-col border-r bg-card">
        <div className="p-6 border-b">
          <div className="flex items-center gap-2">
            <div className="h-9 w-9 rounded-lg bg-primary flex items-center justify-center">
              <GraduationCap className="h-5 w-5 text-primary-foreground" />
            </div>
            <div>
              <p className="font-bold text-primary leading-tight">Moradia UFU</p>
              <p className="text-xs text-muted-foreground">Uberlândia, MG</p>
            </div>
          </div>
        </div>
        <nav className="flex-1 p-3 space-y-1">
          {navItems.map((item) => {
            const Icon = item.icon;
            const active = view === item.id;
            return (
              <button
                key={item.id}
                onClick={() => setView(item.id)}
                className={`w-full flex items-center gap-3 px-3 py-2.5 rounded-md text-sm font-medium transition-colors ${
                  active
                    ? "bg-primary text-primary-foreground"
                    : "text-foreground hover:bg-muted"
                }`}
              >
                <Icon className="h-4 w-4" />
                {item.label}
              </button>
            );
          })}
        </nav>
        <div className="p-4 border-t">
          <p className="text-xs text-muted-foreground">© 2026 Moradia UFU</p>
        </div>
      </aside>

      <div className="flex-1 flex flex-col min-w-0">
        {/* Header */}
        <header className="h-16 border-b bg-card flex items-center justify-between px-4 md:px-8">
          <div className="md:hidden flex items-center gap-2">
            <div className="h-8 w-8 rounded-lg bg-primary flex items-center justify-center">
              <GraduationCap className="h-4 w-4 text-primary-foreground" />
            </div>
            <span className="font-bold text-primary">Moradia UFU</span>
          </div>
          <div className="hidden md:block">
            <h2 className="text-lg font-semibold capitalize">
              {navItems.find((n) => n.id === view)?.label}
            </h2>
          </div>
          <div className="flex items-center gap-2">
            <Button variant="ghost" size="sm">Entrar</Button>
            <Button size="sm" className="bg-primary hover:bg-primary/90">Cadastrar</Button>
          </div>
        </header>

        {/* Mobile nav */}
        <nav className="md:hidden flex overflow-x-auto border-b bg-card px-2 py-1 gap-1">
          {navItems.map((item) => {
            const Icon = item.icon;
            const active = view === item.id;
            return (
              <button
                key={item.id}
                onClick={() => setView(item.id)}
                className={`flex items-center gap-1.5 px-3 py-2 rounded-md text-xs font-medium whitespace-nowrap ${
                  active ? "bg-primary text-primary-foreground" : "text-muted-foreground"
                }`}
              >
                <Icon className="h-3.5 w-3.5" />
                {item.label}
              </button>
            );
          })}
        </nav>

        <main className="flex-1 overflow-y-auto">
          {view === "home" && <HomeView onSearch={() => setView("buscar")} />}
          {view === "buscar" && <BuscarView />}
          {view === "perfil" && <PerfilView />}
          {view === "anuncios" && <AnunciosView />}
          {view === "mensagens" && <MensagensView />}
        </main>
      </div>
    </div>
  );
}

function HomeView({ onSearch }: { onSearch: () => void }) {
  return (
    <div>
      {/* Hero */}
      <section className="bg-gradient-to-br from-primary to-primary/80 text-primary-foreground px-6 md:px-12 py-16 md:py-24">
        <div className="max-w-4xl mx-auto text-center">
          <Badge className="bg-white/15 text-primary-foreground border-0 mb-4 hover:bg-white/20">
            Plataforma oficial de estudantes UFU
          </Badge>
          <h1 className="text-3xl md:text-5xl font-bold leading-tight mb-4">
            Encontre sua moradia ideal perto da UFU
          </h1>
          <p className="text-base md:text-lg opacity-90 mb-8 max-w-2xl mx-auto">
            Repúblicas, quartos e apartamentos verificados em Uberlândia — conectando
            estudantes que vêm de fora com lares confiáveis.
          </p>
          <div className="bg-card rounded-xl p-2 flex flex-col sm:flex-row gap-2 max-w-2xl mx-auto shadow-lg">
            <div className="flex-1 flex items-center gap-2 px-3">
              <Search className="h-4 w-4 text-muted-foreground" />
              <Input
                placeholder="Busque por bairro, campus ou tipo de vaga..."
                className="border-0 focus-visible:ring-0 text-foreground"
              />
            </div>
            <Button onClick={onSearch} className="bg-emerald-600 hover:bg-emerald-700 text-white">
              Buscar agora
            </Button>
          </div>
        </div>
      </section>

      {/* Featured */}
      <section className="px-6 md:px-12 py-12 max-w-7xl mx-auto">
        <div className="flex items-end justify-between mb-6">
          <div>
            <h2 className="text-2xl font-bold">Anúncios em destaque</h2>
            <p className="text-muted-foreground text-sm">Selecionados para estudantes da UFU</p>
          </div>
          <Button variant="ghost" onClick={onSearch}>Ver todos →</Button>
        </div>
        <div className="grid md:grid-cols-3 gap-6">
          {featured.map((p) => (
            <ListingCard key={p.title} {...p} />
          ))}
        </div>
      </section>

      <section className="px-6 md:px-12 pb-16 max-w-7xl mx-auto grid md:grid-cols-3 gap-4">
        {[
          { t: "100% verificados", d: "Anúncios revisados pela nossa equipe." },
          { t: "Perto dos 3 campi", d: "Santa Mônica, Umuarama e Glória." },
          { t: "Sem taxas escondidas", d: "Negocie direto com o anunciante." },
        ].map((b) => (
          <Card key={b.t}>
            <CardContent className="p-5">
              <CheckCircle2 className="h-5 w-5 text-emerald-600 mb-2" />
              <p className="font-semibold">{b.t}</p>
              <p className="text-sm text-muted-foreground">{b.d}</p>
            </CardContent>
          </Card>
        ))}
      </section>
    </div>
  );
}

function ListingCard({ title, price, location, img }: { title: string; price: string; location: string; img: string }) {
  return (
    <Card className="overflow-hidden group hover:shadow-lg transition-shadow pt-0">
      <div className="aspect-[4/3] overflow-hidden bg-muted">
        <img
          src={img}
          alt={title}
          className="w-full h-full object-cover group-hover:scale-105 transition-transform"
          loading="lazy"
        />
      </div>
      <CardContent className="p-4 space-y-2">
        <p className="font-semibold line-clamp-2 min-h-[3rem]">{title}</p>
        <div className="flex items-center gap-1 text-sm text-muted-foreground">
          <MapPin className="h-3.5 w-3.5" />
          {location}
        </div>
        <div className="flex items-center justify-between pt-2">
          <span className="text-lg font-bold text-primary">{price}</span>
          <Button size="sm" variant="outline">Ver detalhes</Button>
        </div>
      </CardContent>
    </Card>
  );
}

function BuscarView() {
  return (
    <div className="flex flex-col lg:flex-row gap-6 p-6 md:p-8 max-w-7xl mx-auto w-full">
      {/* Filters */}
      <aside className="lg:w-72 shrink-0">
        <Card>
          <CardContent className="p-5 space-y-6">
            <div>
              <h3 className="font-semibold mb-3">Campus</h3>
              <div className="space-y-2">
                {["Santa Mônica", "Umuarama", "Glória"].map((c) => (
                  <div key={c} className="flex items-center gap-2">
                    <Checkbox id={c} defaultChecked={c === "Santa Mônica"} />
                    <Label htmlFor={c} className="font-normal">{c}</Label>
                  </div>
                ))}
              </div>
            </div>
            <Separator />
            <div>
              <h3 className="font-semibold mb-3">Tipo de vaga</h3>
              <div className="space-y-2">
                {["Quarto individual", "Quarto compartilhado", "Apartamento inteiro", "República"].map((t) => (
                  <div key={t} className="flex items-center gap-2">
                    <Checkbox id={t} />
                    <Label htmlFor={t} className="font-normal">{t}</Label>
                  </div>
                ))}
              </div>
            </div>
            <Separator />
            <div>
              <h3 className="font-semibold mb-3">Preço máximo</h3>
              <Slider defaultValue={[1200]} max={3000} step={50} />
              <p className="text-sm text-muted-foreground mt-2">Até R$ 1.200/mês</p>
            </div>
            <Separator />
            <div>
              <h3 className="font-semibold mb-3">Comodidades</h3>
              <div className="space-y-2">
                {[
                  { l: "Internet", i: Wifi },
                  { l: "Garagem", i: Car },
                  { l: "Mobília", i: Sofa },
                ].map(({ l, i: Icon }) => (
                  <div key={l} className="flex items-center gap-2">
                    <Checkbox id={l} />
                    <Label htmlFor={l} className="font-normal flex items-center gap-1.5">
                      <Icon className="h-3.5 w-3.5" />
                      {l}
                    </Label>
                  </div>
                ))}
              </div>
            </div>
            <Separator />
            <div>
              <h3 className="font-semibold mb-3">Gênero da casa</h3>
              <div className="space-y-2">
                {["Mista", "Apenas mulheres", "Apenas homens"].map((g) => (
                  <div key={g} className="flex items-center gap-2">
                    <Checkbox id={g} />
                    <Label htmlFor={g} className="font-normal">{g}</Label>
                  </div>
                ))}
              </div>
            </div>
            <Button className="w-full bg-emerald-600 hover:bg-emerald-700 text-white">
              Aplicar filtros
            </Button>
          </CardContent>
        </Card>
      </aside>

      {/* Results */}
      <div className="flex-1">
        <div className="flex items-center justify-between mb-4">
          <p className="text-sm text-muted-foreground">{searchResults.length} imóveis encontrados</p>
        </div>
        <div className="grid sm:grid-cols-2 xl:grid-cols-3 gap-5">
          {searchResults.map((r) => (
            <ListingCard key={r.title} {...r} />
          ))}
        </div>
      </div>
    </div>
  );
}

function PerfilView() {
  return (
    <div className="p-6 md:p-8 max-w-4xl mx-auto w-full">
      <Card>
        <CardContent className="p-8">
          <div className="flex flex-col md:flex-row items-center md:items-start gap-6">
            <Avatar className="h-32 w-32 border-4 border-primary/10">
              <AvatarImage src="https://i.pravatar.cc/200?img=47" />
              <AvatarFallback>CS</AvatarFallback>
            </Avatar>
            <div className="flex-1 text-center md:text-left space-y-2">
              <div className="flex items-center gap-2 justify-center md:justify-start flex-wrap">
                <h2 className="text-2xl font-bold">Camila Santos Oliveira</h2>
                <Badge className="bg-emerald-600 hover:bg-emerald-600 text-white gap-1">
                  <CheckCircle2 className="h-3 w-3" />
                  Aluno UFU Verificado
                </Badge>
              </div>
              <p className="text-muted-foreground">Engenharia Civil • 4º período</p>
              <p className="text-sm text-muted-foreground">📍 Natural de Patos de Minas — MG</p>
              <p className="text-sm pt-2">
                Estudante calma, organizada e responsável. Procurando uma vaga tranquila
                próxima ao campus Santa Mônica para os próximos semestres.
              </p>
            </div>
          </div>

          <Separator className="my-8" />

          <div>
            <h3 className="font-semibold mb-3">Estilo de vida</h3>
            <div className="flex flex-wrap gap-2">
              {[
                "Organizada",
                "Não fumante",
                "Estuda à noite",
                "Sem pets",
                "Quieta",
                "Cozinha em casa",
                "Acorda cedo",
              ].map((t) => (
                <Badge key={t} variant="secondary" className="px-3 py-1.5 text-sm">
                  {t}
                </Badge>
              ))}
            </div>
          </div>

          <Separator className="my-8" />

          <div className="grid sm:grid-cols-3 gap-4">
            {[
              { l: "Anúncios favoritos", v: "12" },
              { l: "Visitas agendadas", v: "3" },
              { l: "Conversas ativas", v: "5" },
            ].map((s) => (
              <div key={s.l} className="bg-muted/50 rounded-lg p-4 text-center">
                <p className="text-2xl font-bold text-primary">{s.v}</p>
                <p className="text-xs text-muted-foreground">{s.l}</p>
              </div>
            ))}
          </div>

          <div className="flex gap-2 mt-8">
            <Button variant="outline" className="flex-1">Editar perfil</Button>
            <Button className="flex-1 bg-primary hover:bg-primary/90">Compartilhar</Button>
          </div>
        </CardContent>
      </Card>
    </div>
  );
}

function AnunciosView() {
  return (
    <div className="p-6 md:p-8 max-w-6xl mx-auto w-full space-y-6">
      <div className="flex flex-col sm:flex-row sm:items-center sm:justify-between gap-4">
        <div>
          <h2 className="text-2xl font-bold">Meus Anúncios</h2>
          <p className="text-muted-foreground text-sm">Gerencie suas vagas oferecidas</p>
        </div>
        <Button className="bg-emerald-600 hover:bg-emerald-700 text-white gap-2">
          <Plus className="h-4 w-4" />
          Criar novo anúncio
        </Button>
      </div>

      <div className="grid sm:grid-cols-3 gap-4">
        {[
          { l: "Anúncios ativos", v: "2" },
          { l: "Visualizações totais", v: "267" },
          { l: "Mensagens recebidas", v: "18" },
        ].map((s) => (
          <Card key={s.l}>
            <CardContent className="p-5">
              <p className="text-sm text-muted-foreground">{s.l}</p>
              <p className="text-2xl font-bold text-primary">{s.v}</p>
            </CardContent>
          </Card>
        ))}
      </div>

      <Card>
        <CardContent className="p-0 divide-y">
          {myListings.map((l) => (
            <div key={l.title} className="p-4 flex flex-col md:flex-row md:items-center gap-4">
              <div className="h-20 w-28 rounded-md bg-muted overflow-hidden shrink-0">
                <img
                  src={`https://images.unsplash.com/photo-1505691938895-1758d7feb511?w=300&q=60`}
                  alt=""
                  className="w-full h-full object-cover"
                />
              </div>
              <div className="flex-1 min-w-0">
                <p className="font-semibold truncate">{l.title}</p>
                <div className="flex items-center gap-3 text-sm text-muted-foreground mt-1">
                  <span className="text-primary font-semibold">{l.price}/mês</span>
                  <span>•</span>
                  <span>{l.views} visualizações</span>
                </div>
                <Badge
                  variant={l.status === "Ativo" ? "default" : "secondary"}
                  className={`mt-2 ${l.status === "Ativo" ? "bg-emerald-600 hover:bg-emerald-600" : ""}`}
                >
                  {l.status}
                </Badge>
              </div>
              <div className="flex gap-2">
                <Button variant="outline" size="sm" className="gap-1.5">
                  <Pencil className="h-3.5 w-3.5" />
                  Editar
                </Button>
                <Button variant="outline" size="sm" className="gap-1.5">
                  <Pause className="h-3.5 w-3.5" />
                  Pausar
                </Button>
              </div>
            </div>
          ))}
        </CardContent>
      </Card>
    </div>
  );
}

function MensagensView() {
  const [activeContact, setActiveContact] = useState(0);
  return (
    <div className="p-4 md:p-6 h-[calc(100vh-4rem)] md:h-[calc(100vh-4rem)]">
      <Card className="h-full overflow-hidden p-0">
        <div className="grid grid-cols-1 md:grid-cols-[320px_1fr] h-full">
          {/* Contacts */}
          <div className="border-r flex flex-col min-h-0">
            <div className="p-4 border-b">
              <Input placeholder="Buscar conversas..." />
            </div>
            <div className="flex-1 overflow-y-auto">
              {contacts.map((c, i) => (
                <button
                  key={c.name}
                  onClick={() => setActiveContact(i)}
                  className={`w-full flex items-center gap-3 p-3 border-b text-left hover:bg-muted/50 transition ${
                    activeContact === i ? "bg-muted" : ""
                  }`}
                >
                  <Avatar>
                    <AvatarImage src={`https://i.pravatar.cc/80?img=${i + 10}`} />
                    <AvatarFallback>{c.name[0]}</AvatarFallback>
                  </Avatar>
                  <div className="flex-1 min-w-0">
                    <div className="flex justify-between items-center">
                      <p className="font-medium truncate text-sm">{c.name}</p>
                      <span className="text-xs text-muted-foreground shrink-0">{c.time}</span>
                    </div>
                    <p className="text-xs text-muted-foreground truncate">{c.last}</p>
                  </div>
                  {c.unread > 0 && (
                    <span className="bg-emerald-600 text-white text-xs rounded-full h-5 w-5 flex items-center justify-center shrink-0">
                      {c.unread}
                    </span>
                  )}
                </button>
              ))}
            </div>
          </div>

          {/* Conversation */}
          <div className="flex flex-col min-h-0">
            <div className="p-4 border-b flex items-center gap-3">
              <Avatar>
                <AvatarImage src={`https://i.pravatar.cc/80?img=${activeContact + 10}`} />
                <AvatarFallback>{contacts[activeContact].name[0]}</AvatarFallback>
              </Avatar>
              <div>
                <p className="font-semibold text-sm">{contacts[activeContact].name}</p>
                <p className="text-xs text-emerald-600">● online</p>
              </div>
            </div>
            <div className="flex-1 overflow-y-auto p-4 space-y-3 bg-muted/30">
              {conversation.map((m, i) => (
                <div
                  key={i}
                  className={`flex ${m.from === "me" ? "justify-end" : "justify-start"}`}
                >
                  <div
                    className={`max-w-[75%] rounded-2xl px-4 py-2 text-sm ${
                      m.from === "me"
                        ? "bg-primary text-primary-foreground rounded-br-sm"
                        : "bg-card border rounded-bl-sm"
                    }`}
                  >
                    {m.text}
                  </div>
                </div>
              ))}
            </div>
            <div className="p-3 border-t flex items-center gap-2 bg-card">
              <Input placeholder="Digite uma mensagem..." className="flex-1" />
              <Button size="icon" className="bg-emerald-600 hover:bg-emerald-700 text-white shrink-0">
                <Send className="h-4 w-4" />
              </Button>
            </div>
          </div>
        </div>
      </Card>
    </div>
  );
}
