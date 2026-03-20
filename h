<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0">
<title>SAMARAN — स्मरण</title>
<link href="https://fonts.googleapis.com/css2?family=Bebas+Neue&family=Outfit:wght@300;400;500;600&family=Noto+Sans+Devanagari:wght@400;700&display=swap" rel="stylesheet">
<style>
*{margin:0;padding:0;box-sizing:border-box;-webkit-tap-highlight-color:transparent}
:root{
  --ink:#04080C;--ink2:#080F16;--ink3:#0D1820;
  --teal:#00C9B1;--teal2:#00A896;--teal-dim:#00C9B133;
  --amber:#FFAA00;--amber-dim:#FFAA0022;
  --rose:#FF4F6A;--rose-dim:#FF4F6A22;
  --text:#E2F0F5;--text2:#7AAFC0;--text3:#2D5068;
  --card:#0D1820;--card2:#111F2C;
  --glow:0 0 40px #00C9B144;
  --font-display:'Bebas Neue',sans-serif;
  --font-body:'Outfit',sans-serif;
  --font-devanagari:'Noto Sans Devanagari',sans-serif;
}
html,body{background:var(--ink);color:var(--text);font-family:var(--font-body);height:100%;overflow:hidden}
 
/* ── CANVAS BG ── */
#bgCanvas{position:fixed;inset:0;z-index:0;pointer-events:none}
 
/* ── APP SHELL ── */
.shell{position:relative;z-index:1;display:flex;flex-direction:column;height:100vh;max-width:420px;margin:0 auto;overflow:hidden}
 
/* ── SCREENS ── */
.screen{position:absolute;inset:0;display:flex;flex-direction:column;overflow-y:auto;overflow-x:hidden;padding-bottom:90px;scrollbar-width:none;transition:transform .45s cubic-bezier(.77,0,.175,1),opacity .45s ease}
.screen::-webkit-scrollbar{display:none}
.screen.hidden-left{transform:translateX(-110%);opacity:0;pointer-events:none}
.screen.hidden-right{transform:translateX(110%);opacity:0;pointer-events:none}
.screen.active{transform:translateX(0);opacity:1}
 
/* ── NAV BAR ── */
.nav{position:fixed;bottom:0;left:50%;transform:translateX(-50%);width:420px;max-width:100%;z-index:100;padding:10px 4px 18px;backdrop-filter:blur(24px);background:#04080Ccc;border-top:1px solid #00C9B122}
.nav-inner{display:flex}
.ni{flex:1;display:flex;flex-direction:column;align-items:center;gap:3px;cursor:pointer;padding:6px 4px;position:relative}
.ni svg{width:20px;height:20px;stroke:var(--text3);fill:none;stroke-width:1.8;stroke-linecap:round;stroke-linejoin:round;transition:.3s}
.ni span{font-size:9px;letter-spacing:.5px;color:var(--text3);transition:.3s;font-weight:500}
.ni.on svg{stroke:var(--teal)}
.ni.on span{color:var(--teal)}
.ni.on::after{content:'';position:absolute;bottom:-4px;left:50%;transform:translateX(-50%);width:4px;height:4px;border-radius:50%;background:var(--teal)}
 
/* ── HEADER ── */
.topbar{display:flex;align-items:center;justify-content:space-between;padding:20px 20px 10px;flex-shrink:0}
.brand{display:flex;flex-direction:column}
.brand-name{font-family:var(--font-display);font-size:30px;letter-spacing:4px;color:var(--teal);line-height:1}
.brand-script{font-family:var(--font-devanagari);font-size:12px;color:var(--text2);margin-top:2px;letter-spacing:1px}
.topbar-pill{display:flex;align-items:center;gap:6px;padding:8px 14px;border-radius:30px;border:1px solid #00C9B133;background:#00C9B108;cursor:pointer;transition:.2s}
.topbar-pill:active{background:#00C9B122}
.topbar-pill span{font-size:12px;color:var(--teal2);font-weight:500}
 
/* ── MEMORY ORB ── */
.orb-wrap{display:flex;justify-content:center;align-items:center;padding:10px 0 6px;flex-shrink:0}
.orb{position:relative;width:160px;height:160px;cursor:pointer}
.orb-ring{position:absolute;inset:0;border-radius:50%;border:1px solid var(--teal-dim);animation:orbRing 4s linear infinite}
.orb-ring:nth-child(2){inset:12px;border-color:#FFAA0022;animation-duration:6s;animation-direction:reverse}
.orb-ring:nth-child(3){inset:24px;border-color:#FF4F6A18;animation-duration:8s}
@keyframes orbRing{from{transform:rotate(0)}to{transform:rotate(360deg)}}
.orb-core{position:absolute;inset:36px;border-radius:50%;background:radial-gradient(circle at 40% 40%, #00C9B155, #080F16 70%);border:1px solid var(--teal2);display:flex;flex-direction:column;align-items:center;justify-content:center;box-shadow:0 0 60px #00C9B133,inset 0 0 30px #00C9B111}
.orb-num{font-family:var(--font-display);font-size:42px;color:var(--teal);line-height:1;animation:orbPulse 3s ease-in-out infinite}
@keyframes orbPulse{0%,100%{text-shadow:0 0 20px #00C9B188}50%{text-shadow:0 0 40px #00C9B1cc,0 0 80px #00C9B155}}
.orb-label{font-size:9px;color:var(--text2);letter-spacing:2px;text-transform:uppercase;margin-top:2px}
.orb-flame{position:absolute;top:-8px;right:28px;font-size:28px;animation:flameWiggle 1.8s ease-in-out infinite}
@keyframes flameWiggle{0%,100%{transform:rotate(-8deg) scale(1)}50%{transform:rotate(8deg) scale(1.15)}}
.orb-badge{position:absolute;bottom:-10px;left:50%;transform:translateX(-50%);background:var(--ink2);border:1px solid var(--amber-dim);border-radius:20px;padding:5px 14px;white-space:nowrap;font-size:11px;color:var(--amber)}
 
/* ── PROGRESS ARC ── */
.progress-arc-wrap{padding:0 20px;flex-shrink:0}
.arc-row{display:flex;align-items:center;gap:12px}
.arc-info{flex:1}
.arc-title{font-size:11px;color:var(--text3);letter-spacing:1px;text-transform:uppercase}
.arc-count{font-family:var(--font-display);font-size:28px;color:var(--text);letter-spacing:2px;margin-top:2px}
.progress-track{height:4px;background:#0D1820;border-radius:2px;margin-top:10px;overflow:hidden}
.progress-fill{height:100%;border-radius:2px;background:linear-gradient(90deg,var(--teal2),var(--teal));transition:width 1.2s cubic-bezier(.34,1.56,.64,1)}
 
/* ── PILL TABS ── */
.pill-tabs{display:flex;gap:6px;padding:14px 20px 8px;overflow-x:auto;scrollbar-width:none;flex-shrink:0}
.pill-tabs::-webkit-scrollbar{display:none}
.pill{padding:8px 18px;border-radius:30px;font-size:12px;font-weight:500;cursor:pointer;border:1px solid var(--text3)33;color:var(--text2);background:transparent;white-space:nowrap;transition:.25s;font-family:var(--font-body)}
.pill.on{background:var(--teal);color:var(--ink);border-color:var(--teal);font-weight:600}
.pill-cat{color:var(--text2)}
 
/* ── TASK CARDS ── */
.task-feed{padding:0 16px;display:flex;flex-direction:column;gap:10px;flex-shrink:0}
.task-card{background:var(--card);border:1px solid #0D1820;border-radius:16px;padding:16px;display:flex;align-items:center;gap:14px;cursor:pointer;transition:.25s;position:relative;overflow:hidden}
.task-card::before{content:'';position:absolute;left:0;top:0;bottom:0;width:3px;border-radius:3px 0 0 3px}
.task-card.cat-office::before{background:var(--teal)}
.task-card.cat-health::before{background:#6BCB77}
.task-card.cat-personal::before{background:#AA8FFF}
.task-card.cat-shopping::before{background:var(--amber)}
.task-card.cat-home::before{background:var(--rose)}
.task-card:active{transform:scale(.98)}
.task-card.done{opacity:.45}
.check-ring{width:26px;height:26px;border-radius:50%;border:2px solid var(--text3);display:flex;align-items:center;justify-content:center;flex-shrink:0;transition:.3s}
.check-ring.done{background:var(--teal);border-color:var(--teal)}
.check-ring.done::after{content:'✓';color:var(--ink);font-size:13px;font-weight:700}
.task-info{flex:1;min-width:0}
.task-name{font-size:14px;font-weight:500;white-space:nowrap;overflow:hidden;text-overflow:ellipsis}
.task-meta{display:flex;align-items:center;gap:8px;margin-top:4px}
.task-time{font-size:11px;color:var(--text2)}
.cat-chip{font-size:10px;padding:2px 8px;border-radius:10px;font-weight:500}
.chip-office{background:#00C9B118;color:var(--teal)}
.chip-health{background:#6BCB7718;color:#6BCB77}
.chip-personal{background:#AA8FFF18;color:#AA8FFF}
.chip-shopping{background:#FFAA0018;color:var(--amber)}
.chip-home{background:#FF4F6A18;color:var(--rose)}
.pri-dot{width:6px;height:6px;border-radius:50%;flex-shrink:0}
.ph{background:var(--rose)}.pm{background:var(--amber)}.pl{background:var(--teal)}
 
/* ── SECTION HEADER ── */
.sec-head{display:flex;align-items:center;justify-content:space-between;padding:16px 20px 10px;flex-shrink:0}
.sec-title{font-family:var(--font-display);font-size:20px;letter-spacing:2px;color:var(--text2)}
.sec-action{font-size:12px;color:var(--teal);font-weight:500;cursor:pointer}
 
/* ── MILA KYA ── */
.mila-hero{margin:0 16px 14px;border-radius:20px;background:linear-gradient(135deg,#111F2C,#0A151D);border:1px solid var(--amber-dim);padding:20px;position:relative;overflow:hidden}
.mila-hero::after{content:'?';position:absolute;right:-10px;top:-20px;font-family:var(--font-display);font-size:140px;color:#FFAA0008;line-height:1;pointer-events:none}
.mila-alert{display:flex;align-items:flex-start;gap:12px;background:#FFAA0010;border-radius:14px;padding:14px;border:1px solid #FFAA0033}
.mila-icon{font-size:28px;flex-shrink:0}
.mila-msg{font-size:13px;line-height:1.6;color:var(--text)}
.mila-msg strong{color:var(--amber)}
.mila-btns{display:flex;gap:8px;margin-top:16px}
.mila-btn{flex:1;padding:11px;border-radius:12px;border:none;font-size:13px;font-weight:600;cursor:pointer;font-family:var(--font-body);transition:.2s}
.mila-btn-yes{background:var(--teal);color:var(--ink)}
.mila-btn-no{background:#FFAA0022;color:var(--amber);border:1px solid var(--amber-dim)}
.mila-btn:active{transform:scale(.97)}
 
.mila-item-grid{display:flex;flex-direction:column;gap:8px;padding:0 16px;flex-shrink:0}
.mila-item{display:flex;align-items:center;gap:12px;background:var(--card);border:1px solid #0D2030;border-radius:14px;padding:14px}
.mila-item-icon{width:44px;height:44px;border-radius:12px;background:var(--card2);display:flex;align-items:center;justify-content:center;font-size:22px;flex-shrink:0}
.mila-item-info{flex:1}
.mila-item-name{font-size:14px;font-weight:500}
.mila-item-loc{font-size:11px;color:var(--text2);margin-top:3px}
.mila-item-side{text-align:right}
.mila-timer{font-size:12px;padding:4px 10px;border-radius:8px;background:var(--amber-dim);color:var(--amber);font-weight:500}
.mila-miss{font-size:10px;color:var(--text3);margin-top:4px}
 
/* ── LEADERBOARD ── */
.lb-podium{display:flex;align-items:flex-end;justify-content:center;gap:12px;padding:20px 20px 0;flex-shrink:0}
.podium-slot{display:flex;flex-direction:column;align-items:center;gap:8px}
.podium-avatar{border-radius:50%;display:flex;align-items:center;justify-content:center;font-family:var(--font-display);font-weight:700}
.p1 .podium-avatar{width:64px;height:64px;font-size:20px;box-shadow:0 0 30px #FFD70066}
.p2 .podium-avatar,.p3 .podium-avatar{width:52px;height:52px;font-size:16px}
.podium-name{font-size:11px;color:var(--text2);font-weight:500;max-width:70px;text-align:center;overflow:hidden;text-overflow:ellipsis;white-space:nowrap}
.podium-streak{font-family:var(--font-display);font-size:14px;letter-spacing:1px}
.podium-base{border-radius:10px 10px 0 0;width:80px;display:flex;align-items:center;justify-content:center}
.pb1{height:60px;background:linear-gradient(180deg,#FFD70022,#FFD70011);border:1px solid #FFD70033}
.pb2{height:42px;background:linear-gradient(180deg,#AAAAAA18,#AAAAAA0A);border:1px solid #AAAAAA22}
.pb3{height:30px;background:linear-gradient(180deg,#CD7F3218,#CD7F320A);border:1px solid #CD7F3222}
.lb-list{padding:0 16px;display:flex;flex-direction:column;gap:8px;flex-shrink:0}
.lb-row{display:flex;align-items:center;gap:12px;background:var(--card);border:1px solid #0D2030;border-radius:14px;padding:13px 14px;transition:.2s}
.lb-row.me-row{background:#00C9B108;border-color:var(--teal-dim)}
.lb-rank{font-family:var(--font-display);font-size:18px;width:28px;text-align:center;color:var(--text3)}
.lb-av{width:36px;height:36px;border-radius:50%;display:flex;align-items:center;justify-content:center;font-family:var(--font-display);font-size:13px;flex-shrink:0}
.lb-info{flex:1}
.lb-uname{font-size:13px;font-weight:500}
.lb-detail{font-size:10px;color:var(--text2);margin-top:2px}
.lb-streak-val{font-family:var(--font-display);font-size:20px;color:var(--amber);letter-spacing:1px}
.lb-flame{font-size:14px}
 
/* ── STATS GRID ── */
.stats-grid{display:grid;grid-template-columns:1fr 1fr;gap:10px;padding:0 16px;flex-shrink:0}
.stat-tile{background:var(--card);border:1px solid #0D2030;border-radius:16px;padding:16px;position:relative;overflow:hidden}
.stat-tile::after{content:attr(data-glyph);position:absolute;right:-4px;bottom:-8px;font-family:var(--font-display);font-size:64px;opacity:.06;line-height:1;pointer-events:none;color:var(--teal)}
.stat-num{font-family:var(--font-display);font-size:32px;color:var(--teal);letter-spacing:2px;line-height:1}
.stat-lbl{font-size:10px;color:var(--text2);margin-top:4px;letter-spacing:.5px;text-transform:uppercase}
 
/* ── LANGUAGE SCREEN ── */
.lang-masthead{padding:20px 20px 6px;flex-shrink:0}
.lang-headline{font-family:var(--font-display);font-size:42px;letter-spacing:3px;color:var(--teal);line-height:1}
.lang-sub{font-size:13px;color:var(--text2);margin-top:6px;line-height:1.5}
.lang-list{padding:0 16px;display:flex;flex-direction:column;gap:8px;flex-shrink:0}
.lang-row{display:flex;align-items:center;gap:14px;background:var(--card);border:1.5px solid #0D2030;border-radius:16px;padding:16px;cursor:pointer;transition:.25s;position:relative}
.lang-row.active{border-color:var(--teal);background:#00C9B10A}
.lang-row.locked{opacity:.4;cursor:not-allowed}
.lang-flag{width:40px;height:40px;border-radius:10px;display:flex;align-items:center;justify-content:center;font-size:22px;flex-shrink:0}
.lang-row-info{flex:1}
.lang-row-name{font-size:15px;font-weight:600}
.lang-row-script{font-size:12px;color:var(--text2);margin-top:2px}
.lang-row-preview{font-size:11px;color:var(--text3);margin-top:4px;font-style:italic}
.lang-check{width:24px;height:24px;border-radius:50%;border:2px solid var(--text3);display:flex;align-items:center;justify-content:center;flex-shrink:0;transition:.3s}
.lang-row.active .lang-check{background:var(--teal);border-color:var(--teal);color:var(--ink);font-size:13px;font-weight:700}
.lang-badge{font-size:9px;padding:2px 8px;border-radius:8px;font-weight:600}
.lb-live{background:#00C9B122;color:var(--teal)}
.lb-soon{background:#FFAA0018;color:var(--amber)}
.preview-box{margin:12px 16px;background:#00C9B10A;border:1px solid var(--teal-dim);border-radius:16px;padding:16px;flex-shrink:0}
.preview-label{font-size:10px;color:var(--text3);letter-spacing:1px;text-transform:uppercase;margin-bottom:8px}
.preview-text{font-size:14px;color:var(--teal);font-style:italic;line-height:1.6}
 
/* ── PERSONA SECTION ── */
.persona-cards{display:flex;gap:10px;padding:0 16px;flex-shrink:0}
.persona-card{flex:1;border-radius:18px;padding:18px 14px;border:1.5px solid transparent;cursor:pointer;transition:.3s;position:relative;overflow:hidden}
.persona-card::before{content:'';position:absolute;inset:0;opacity:.06}
.pc-maa{background:#00C9B108;border-color:#00C9B122}
.pc-maa::before{background:radial-gradient(circle at 30% 70%,var(--teal),transparent)}
.pc-sec{background:#0D1820;border-color:#FFAA0022}
.pc-sec::before{background:radial-gradient(circle at 70% 30%,var(--amber),transparent)}
.persona-card.active.pc-maa{border-color:var(--teal);background:#00C9B115}
.persona-card.active.pc-sec{border-color:var(--amber);background:#FFAA0010}
.pc-icon{font-size:28px;margin-bottom:8px}
.pc-name{font-family:var(--font-display);font-size:18px;letter-spacing:1px}
.pc-maa .pc-name{color:var(--teal)}
.pc-sec .pc-name{color:var(--amber)}
.pc-sample{font-size:11px;color:var(--text2);margin-top:6px;line-height:1.5;font-style:italic}
.pc-active-badge{position:absolute;top:10px;right:10px;font-size:9px;padding:3px 8px;border-radius:8px;font-weight:600}
.pc-maa .pc-active-badge{background:var(--teal-dim);color:var(--teal)}
.pc-sec .pc-active-badge{background:var(--amber-dim);color:var(--amber)}
 
/* ── SETTINGS ITEMS ── */
.settings-group{margin:0 16px 12px;background:var(--card);border:1px solid #0D2030;border-radius:18px;overflow:hidden;flex-shrink:0}
.settings-group-title{padding:14px 18px 8px;font-size:10px;color:var(--text3);letter-spacing:2px;text-transform:uppercase;border-bottom:1px solid #0D2030}
.setting-item{display:flex;align-items:center;gap:14px;padding:16px 18px;border-bottom:1px solid #07111A}
.setting-item:last-child{border-bottom:none}
.si-icon{width:36px;height:36px;border-radius:10px;display:flex;align-items:center;justify-content:center;font-size:17px;flex-shrink:0}
.si-info{flex:1}
.si-label{font-size:14px;font-weight:500}
.si-desc{font-size:11px;color:var(--text3);margin-top:2px}
.toggle{width:46px;height:26px;border-radius:13px;background:#0D1820;border:1px solid #1A3044;cursor:pointer;position:relative;transition:.35s;flex-shrink:0}
.toggle::after{content:'';position:absolute;width:20px;height:20px;border-radius:50%;background:var(--text3);top:2px;left:2px;transition:.35s}
.toggle.on{background:var(--teal);border-color:var(--teal)}
.toggle.on::after{left:22px;background:#fff}
 
/* ── CHALLENGE OVERLAY ── */
.overlay{position:fixed;inset:0;z-index:500;display:none;flex-direction:column;justify-content:flex-end;background:#000000bb;backdrop-filter:blur(8px)}
.overlay.open{display:flex}
.challenge-sheet{background:var(--ink2);border:1px solid #00C9B133;border-radius:28px 28px 0 0;padding:28px 24px 44px;animation:sheetUp .35s cubic-bezier(.34,1.56,.64,1)}
@keyframes sheetUp{from{transform:translateY(100%)}to{transform:translateY(0)}}
.cs-eyebrow{display:flex;align-items:center;gap:8px;margin-bottom:14px}
.cs-dot{width:8px;height:8px;border-radius:50%;background:var(--rose);animation:dotBlink .8s ease-in-out infinite}
@keyframes dotBlink{0%,100%{opacity:1}50%{opacity:.3}}
.cs-label{font-size:11px;color:var(--rose);letter-spacing:2px;text-transform:uppercase;font-weight:600}
.cs-title{font-family:var(--font-display);font-size:26px;letter-spacing:2px;color:var(--text);margin-bottom:14px;line-height:1.1}
.cs-bubble{background:var(--ink3);border-radius:16px;padding:16px;border-left:3px solid var(--amber);margin-bottom:22px}
.cs-msg{font-size:14px;color:var(--text);line-height:1.65}
.cs-snooze-bar{display:flex;gap:4px;margin-bottom:18px}
.snooze-pip{flex:1;height:3px;border-radius:2px;background:#1A3044}
.snooze-pip.used{background:var(--rose)}
.cs-btns{display:flex;gap:10px}
.cs-btn{flex:1;padding:15px;border-radius:16px;border:none;font-size:14px;font-weight:600;cursor:pointer;font-family:var(--font-body);letter-spacing:.3px;transition:.2s}
.cs-btn-done{background:var(--teal);color:var(--ink)}
.cs-btn-done:active{background:var(--teal2)}
.cs-btn-snooze{background:#1A3044;color:var(--text2)}
 
/* ── TOAST ── */
.toast{position:fixed;top:20px;left:50%;transform:translateX(-50%) translateY(-100px);background:var(--card2);border:1px solid var(--teal-dim);border-radius:16px;padding:12px 20px;z-index:600;transition:.4s cubic-bezier(.34,1.56,.64,1);max-width:360px;width:88%;backdrop-filter:blur(20px)}
.toast.show{transform:translateX(-50%) translateY(0)}
.toast-top{font-family:var(--font-display);font-size:16px;letter-spacing:1px;color:var(--amber)}
.toast-bot{font-size:12px;color:var(--text2);margin-top:3px;line-height:1.4}
 
/* ── CONFETTI ── */
.conf-wrap{pointer-events:none;position:fixed;inset:0;z-index:590;overflow:hidden}
.cp{position:absolute;border-radius:2px;animation:cpFall linear forwards}
@keyframes cpFall{0%{transform:translateY(-20px) rotate(0deg);opacity:1}100%{transform:translateY(110vh) rotate(900deg);opacity:0}}
 
/* ── FAB ── */
.fab{position:fixed;bottom:96px;right:16px;width:54px;height:54px;border-radius:50%;background:var(--rose);border:none;cursor:pointer;z-index:200;display:flex;align-items:center;justify-content:center;box-shadow:0 4px 24px #FF4F6A55;transition:.25s;font-size:22px}
.fab:active{transform:scale(.92)}
 
/* ── WEEK STRIP ── */
.week-strip{display:flex;gap:6px;padding:0 16px 12px;overflow-x:auto;scrollbar-width:none;flex-shrink:0}
.week-strip::-webkit-scrollbar{display:none}
.wd{flex-shrink:0;width:48px;display:flex;flex-direction:column;align-items:center;gap:4px;padding:10px 0;border-radius:14px;cursor:pointer;border:1px solid transparent;transition:.25s}
.wd.sel{background:var(--teal);border-color:var(--teal)}
.wd-name{font-size:9px;font-weight:600;color:var(--text3);letter-spacing:.5px}
.wd-num{font-family:var(--font-display);font-size:20px;color:var(--text);line-height:1}
.wd.sel .wd-name,.wd.sel .wd-num{color:var(--ink)}
.wd-done{width:5px;height:5px;border-radius:50%;background:var(--teal);opacity:0;transition:.3s}
.wd.completed .wd-done{opacity:1}
.wd.sel .wd-done{background:var(--ink)}
</style>
</head>
<body>
<canvas id="bgCanvas"></canvas>
<div class="shell">
 
<!-- ══ HOME ══ -->
<div class="screen active" id="sc-home">
  <div class="topbar">
    <div class="brand"><div class="brand-name">SAMARAN</div><div class="brand-script">स्मरण — याद रखो, जीतो</div></div>
    <div class="topbar-pill" id="personaPill" onclick="nextPersona()"><span id="personaLabel">🏠 Maa Mode</span></div>
  </div>
 
  <div class="orb-wrap">
    <div class="orb" onclick="orbClick()">
      <div class="orb-ring"></div>
      <div class="orb-ring"></div>
      <div class="orb-ring"></div>
      <div class="orb-core">
        <div class="orb-num" id="orbNum">12</div>
        <div class="orb-label">DAY STREAK</div>
      </div>
      <div class="orb-flame">🔥</div>
      <div class="orb-badge" id="orbBadge">Week Warrior 🔥</div>
    </div>
  </div>
 
  <div class="progress-arc-wrap">
    <div class="arc-row">
      <div class="arc-info">
        <div class="arc-title">Today's Mission</div>
        <div class="arc-count" id="taskProgress">4 / 6</div>
      </div>
      <div style="font-size:11px;color:var(--text2);text-align:right">
        <div style="color:var(--teal);font-size:20px;font-family:var(--font-display)" id="pctLabel">67%</div>
        <div>Complete</div>
      </div>
    </div>
    <div class="progress-track"><div class="progress-fill" id="progFill" style="width:67%"></div></div>
  </div>
 
  <div class="sec-head">
    <div class="sec-title">TODAY</div>
    <div class="sec-action" onclick="nav('plan')">See Week →</div>
  </div>
 
  <div class="pill-tabs">
    <button class="pill on" onclick="filterCat('all',this)">All</button>
    <button class="pill" onclick="filterCat('Office',this)">Office</button>
    <button class="pill" onclick="filterCat('Health',this)">Health</button>
    <button class="pill" onclick="filterCat('Personal',this)">Personal</button>
    <button class="pill" onclick="filterCat('Shopping',this)">Shopping</button>
    <button class="pill" onclick="filterCat('Home',this)">Home</button>
  </div>
 
  <div class="task-feed" id="homeFeed"></div>
  <div style="height:10px;flex-shrink:0"></div>
 
  <div class="stats-grid">
    <div class="stat-tile" data-glyph="RANK"><div class="stat-num">#4</div><div class="stat-lbl">Leaderboard</div></div>
    <div class="stat-tile" data-glyph="WIN"><div class="stat-num">96%</div><div class="stat-lbl">Weekly rate</div></div>
    <div class="stat-tile" data-glyph="DAY"><div class="stat-num">19</div><div class="stat-lbl">Best streak</div></div>
    <div class="stat-tile" data-glyph="🏅"><div class="stat-num">7</div><div class="stat-lbl">Badges</div></div>
  </div>
  <div style="height:10px;flex-shrink:0"></div>
</div>
 
<!-- ══ PLANNER ══ -->
<div class="screen hidden-right" id="sc-plan">
  <div class="topbar">
    <div class="brand"><div class="brand-name">PLANNER</div><div class="brand-script">Weekly mission schedule</div></div>
    <div class="topbar-pill"><span>Mar 17–23</span></div>
  </div>
  <div class="week-strip" id="weekStrip"></div>
  <div class="sec-head" id="planDayHead"><div class="sec-title">MON · 17</div></div>
  <div class="task-feed" id="planFeed"></div>
  <div style="padding:0 16px;margin-top:6px;flex-shrink:0">
    <button style="width:100%;padding:14px;background:transparent;border:1.5px dashed var(--text3)33;border-radius:14px;color:var(--text3);font-size:13px;cursor:pointer;font-family:var(--font-body);transition:.2s" onclick="toast('Add Task','Feature launching soon — plan your full week!')">+ Add task to this day</button>
  </div>
  <div style="height:10px;flex-shrink:0"></div>
</div>
 
<!-- ══ MILA KYA ══ -->
<div class="screen hidden-right" id="sc-mila">
  <div class="topbar">
    <div class="brand"><div class="brand-name">MILA KYA?</div><div class="brand-script">Pre-departure item checker</div></div>
    <div class="topbar-pill"><span>⏰ 8:58 AM</span></div>
  </div>
 
  <div class="mila-hero" style="margin:0 16px 14px">
    <div class="mila-alert">
      <div class="mila-icon">🔑</div>
      <div>
        <div style="font-size:10px;color:var(--amber);letter-spacing:1px;text-transform:uppercase;margin-bottom:4px">Active Reminder</div>
        <div class="mila-msg" id="milaMainMsg"><strong>Chabiyaan uthayi?</strong> Hook ke paas dekho bhai — SAMARAN yaad dila raha hai! 😄</div>
      </div>
    </div>
    <div class="mila-btns">
      <button class="mila-btn mila-btn-yes" onclick="milaYes()">✓ Mila! Got it</button>
      <button class="mila-btn mila-btn-no" onclick="milaNo()">Nahi mila :(</button>
    </div>
  </div>
 
  <div class="sec-head"><div class="sec-title">MY ITEMS</div><div class="sec-action" onclick="toast('Add Item','Tap + to register your daily essentials!')">+ Add</div></div>
  <div class="mila-item-grid" id="milaGrid"></div>
 
  <div class="sec-head" style="margin-top:8px"><div class="sec-title">THIS WEEK</div></div>
  <div style="margin:0 16px;background:var(--card);border-radius:16px;padding:16px;border:1px solid #0D2030;flex-shrink:0">
    <div id="milaReport" style="font-size:13px;color:var(--text2);line-height:2"></div>
  </div>
  <div style="height:10px;flex-shrink:0"></div>
</div>
 
<!-- ══ LEADERBOARD ══ -->
<div class="screen hidden-right" id="sc-board">
  <div class="topbar">
    <div class="brand"><div class="brand-name">BOARD</div><div class="brand-script">Weekly champions</div></div>
    <div class="topbar-pill"><span>Resets Mon</span></div>
  </div>
  <div class="lb-podium" id="podium"></div>
  <div style="height:16px;flex-shrink:0"></div>
  <div class="pill-tabs">
    <button class="pill on" id="lbGTab" onclick="showLB('global',this)">🌍 Global</button>
    <button class="pill" id="lbFTab" onclick="showLB('friends',this)">👥 Friends</button>
  </div>
  <div class="lb-list" id="lbList"></div>
  <div style="height:10px;flex-shrink:0"></div>
</div>
 
<!-- ══ SETTINGS ══ -->
<div class="screen hidden-right" id="sc-set">
  <div class="topbar">
    <div class="brand"><div class="brand-name">SETTINGS</div><div class="brand-script">Preferences & privacy</div></div>
  </div>
 
  <div class="sec-head"><div class="sec-title">PERSONALITY</div></div>
  <div class="persona-cards" id="personaCards">
    <div class="persona-card pc-maa active" onclick="setPers('maa')" id="pcMaa">
      <div class="pc-icon">🏠</div>
      <div class="pc-name">MAA MODE</div>
      <div class="pc-sample" id="pcMaaSample">"Beta! Dawai le lo — SAMARAN yaad karta hai!"</div>
      <div class="pc-active-badge" id="pcMaaBadge">ACTIVE</div>
    </div>
    <div class="persona-card pc-sec" onclick="setPers('sec')" id="pcSec">
      <div class="pc-icon">🏢</div>
      <div class="pc-name">SECRETARY</div>
      <div class="pc-sample" id="pcSecSample">"Deadline in 30 min. Execute now."</div>
      <div class="pc-active-badge" style="display:none" id="pcSecBadge">ACTIVE</div>
    </div>
  </div>
 
  <div class="sec-head" style="margin-top:10px"><div class="sec-title">LANGUAGE</div></div>
  <div class="lang-list" id="langList"></div>
  <div class="preview-box" id="langPreviewBox">
    <div class="preview-label">Live Preview</div>
    <div class="preview-text" id="langPreviewText">Chabiyaan uthayi? Hook ke paas dekho bhai! SAMARAN yaad karata hai! 🔑</div>
  </div>
 
  <div class="settings-group" style="margin-top:10px">
    <div class="settings-group-title">🔒 Privacy & Security</div>
    <div class="setting-item"><div class="si-icon" style="background:#00C9B118">🔐</div><div class="si-info"><div class="si-label">End-to-End Encryption</div><div class="si-desc">AES-256 · Zero-knowledge</div></div><button class="toggle on" onclick="this.classList.toggle('on')"></button></div>
    <div class="setting-item"><div class="si-icon" style="background:#AA8FFF18">👆</div><div class="si-info"><div class="si-label">Biometric Lock</div><div class="si-desc">Face ID · Fingerprint</div></div><button class="toggle on" onclick="this.classList.toggle('on')"></button></div>
    <div class="setting-item"><div class="si-icon" style="background:#FFAA0018">🕵️</div><div class="si-info"><div class="si-label">Stealth Mode</div><div class="si-desc">Disguise app as calculator</div></div><button class="toggle" onclick="this.classList.toggle('on')"></button></div>
    <div class="setting-item"><div class="si-icon" style="background:#00C9B118">📱</div><div class="si-info"><div class="si-label">Local-only Mila Kya?</div><div class="si-desc">Items never leave your device</div></div><button class="toggle on" onclick="this.classList.toggle('on')"></button></div>
  </div>
 
  <div class="settings-group">
    <div class="settings-group-title">🔔 Notifications</div>
    <div class="setting-item"><div class="si-icon" style="background:#FF4F6A18">⚡</div><div class="si-info"><div class="si-label">Challenge Reminders</div><div class="si-desc">Can't be swiped away</div></div><button class="toggle on" onclick="this.classList.toggle('on')"></button></div>
    <div class="setting-item"><div class="si-icon" style="background:#FFAA0018">🔍</div><div class="si-info"><div class="si-label">Mila Kya? Alerts</div><div class="si-desc">Pre-departure checks</div></div><button class="toggle on" onclick="this.classList.toggle('on')"></button></div>
    <div class="setting-item"><div class="si-icon" style="background:#00C9B118">🔥</div><div class="si-info"><div class="si-label">Streak Reminders</div><div class="si-desc">Daily completion nudge</div></div><button class="toggle on" onclick="this.classList.toggle('on')"></button></div>
  </div>
 
  <div class="settings-group">
    <div class="settings-group-title">⚖️ Your Data Rights</div>
    <div class="setting-item" style="cursor:pointer" onclick="toast('📥 Download Data','Preparing your PDF export...')"><div class="si-icon" style="background:#00C9B118">📥</div><div class="si-info"><div class="si-label">Download My Data</div><div class="si-desc">PDF or JSON export</div></div><span style="color:var(--text3);font-size:18px">›</span></div>
    <div class="setting-item" style="cursor:pointer" onclick="toast('🔄 Export History','Streak & task history ready!')"><div class="si-icon" style="background:#AA8FFF18">🔄</div><div class="si-info"><div class="si-label">Export History</div><div class="si-desc">Streaks, tasks, badges</div></div><span style="color:var(--text3);font-size:18px">›</span></div>
    <div class="setting-item" style="cursor:pointer" onclick="toast('🗑️ Delete Account','All data wiped in 24 hrs')"><div class="si-icon" style="background:#FF4F6A18">🗑️</div><div class="si-info"><div class="si-label" style="color:var(--rose)">Delete Account</div><div class="si-desc">Permanent — 24hr window</div></div><span style="color:var(--text3);font-size:18px">›</span></div>
  </div>
 
  <div style="text-align:center;padding:20px;color:var(--text3);font-size:10px;letter-spacing:1px;flex-shrink:0">SAMARAN v2.0 · DPDP ACT 2023 · YOUR DATA BELONGS TO YOU</div>
</div>
 
<!-- ══ NAV ══ -->
<nav class="nav">
  <div class="nav-inner">
    <div class="ni on" id="ni-home" onclick="nav('home')">
      <svg viewBox="0 0 24 24"><path d="M3 9l9-7 9 7v11a2 2 0 01-2 2H5a2 2 0 01-2-2z"/><polyline points="9,22 9,12 15,12 15,22"/></svg>
      <span>Home</span>
    </div>
    <div class="ni" id="ni-plan" onclick="nav('plan')">
      <svg viewBox="0 0 24 24"><rect x="3" y="4" width="18" height="18" rx="2"/><line x1="16" y1="2" x2="16" y2="6"/><line x1="8" y1="2" x2="8" y2="6"/><line x1="3" y1="10" x2="21" y2="10"/></svg>
      <span>Plan</span>
    </div>
    <div class="ni" id="ni-mila" onclick="nav('mila')">
      <svg viewBox="0 0 24 24"><circle cx="11" cy="11" r="8"/><line x1="21" y1="21" x2="16.65" y2="16.65"/></svg>
      <span>Mila Kya?</span>
    </div>
    <div class="ni" id="ni-board" onclick="nav('board')">
      <svg viewBox="0 0 24 24"><polyline points="22,12 18,12 15,21 9,3 6,12 2,12"/></svg>
      <span>Board</span>
    </div>
    <div class="ni" id="ni-set" onclick="nav('set')">
      <svg viewBox="0 0 24 24"><circle cx="12" cy="12" r="3"/><path d="M19.4 15a1.65 1.65 0 00.33 1.82l.06.06a2 2 0 010 2.83 2 2 0 01-2.83 0l-.06-.06a1.65 1.65 0 00-1.82-.33 1.65 1.65 0 00-1 1.51V21a2 2 0 01-4 0v-.09A1.65 1.65 0 009 19.4a1.65 1.65 0 00-1.82.33l-.06.06a2 2 0 01-2.83-2.83l.06-.06A1.65 1.65 0 004.68 15a1.65 1.65 0 00-1.51-1H3a2 2 0 010-4h.09A1.65 1.65 0 004.6 9a1.65 1.65 0 00-.33-1.82l-.06-.06a2 2 0 012.83-2.83l.06.06A1.65 1.65 0 009 4.68a1.65 1.65 0 001-1.51V3a2 2 0 014 0v.09a1.65 1.65 0 001 1.51 1.65 1.65 0 001.82-.33l.06-.06a2 2 0 012.83 2.83l-.06.06A1.65 1.65 0 0019.4 9a1.65 1.65 0 001.51 1H21a2 2 0 010 4h-.09a1.65 1.65 0 00-1.51 1z"/></svg>
      <span>Settings</span>
    </div>
  </div>
</nav>
</div>
 
<!-- Challenge overlay -->
<div class="overlay" id="challengeOverlay">
  <div class="challenge-sheet">
    <div class="cs-eyebrow"><div class="cs-dot"></div><div class="cs-label">SAMARAN Challenge</div></div>
    <div class="cs-title" id="csTitle">Take Evening Medicine 💊</div>
    <div class="cs-bubble"><div class="cs-msg" id="csMsg">Beta! Dawai pi li? Doctor ne bola tha na daily lene ko — SAMARAN yaad karata hai! Abhi le lo!</div></div>
    <div class="cs-snooze-bar"><div class="snooze-pip" id="sp1"></div><div class="snooze-pip" id="sp2"></div></div>
    <div class="cs-btns">
      <button class="cs-btn cs-btn-done" onclick="challengeDone()">✓ Done — Mark Complete</button>
      <button class="cs-btn cs-btn-snooze" id="snoozeBtn" onclick="challengeSnooze()">⏰ Snooze</button>
    </div>
  </div>
</div>
 
<button class="fab" onclick="openChallenge()" title="Trigger Challenge">⚡</button>
<div class="toast" id="toastEl"><div class="toast-top" id="toastTop"></div><div class="toast-bot" id="toastBot"></div></div>
<div class="conf-wrap" id="confWrap"></div>
 
<script>
// ── DATA ──
const tasks=[
  {id:1,name:'Team standup',time:'10:00 AM',cat:'Office',done:true,pri:'h',day:1},
  {id:2,name:'Submit project report',time:'5:00 PM',cat:'Office',done:false,pri:'h',day:1},
  {id:3,name:'Morning walk 30 min',time:'7:00 AM',cat:'Health',done:true,pri:'m',day:1},
  {id:4,name:'Buy groceries',time:'7:00 PM',cat:'Shopping',done:true,pri:'l',day:1},
  {id:5,name:'Call parents',time:'8:00 PM',cat:'Personal',done:false,pri:'m',day:1},
  {id:6,name:'Take evening medicine',time:'9:00 PM',cat:'Health',done:true,pri:'h',day:1},
  {id:7,name:'Review weekly goals',time:'10:00 AM',cat:'Office',done:false,pri:'h',day:2},
  {id:8,name:'Yoga 45 min',time:'6:30 AM',cat:'Health',done:true,pri:'m',day:2},
  {id:9,name:'Pay electricity bill',time:'11:00 AM',cat:'Home',done:false,pri:'h',day:3},
  {id:10,name:'Read 20 pages',time:'9:00 PM',cat:'Personal',done:true,pri:'l',day:3},
  {id:11,name:'Fix leaking tap',time:'3:00 PM',cat:'Home',done:false,pri:'m',day:4},
  {id:12,name:'Client presentation',time:'2:00 PM',cat:'Office',done:false,pri:'h',day:5},
];
const milaItems=[
  {id:1,icon:'🔑',name:'Keys',place:'Hook near main door',time:'8:58 AM',miss:4},
  {id:2,icon:'👛',name:'Wallet',place:'Bedside table',time:'8:58 AM',miss:2},
  {id:3,icon:'🔌',name:'Charger',place:'Desk socket',time:'8:55 AM',miss:3},
  {id:4,icon:'🪪',name:'Office ID',place:'Wallet / bag',time:'8:57 AM',miss:1},
  {id:5,icon:'👓',name:'Glasses',place:'TV cabinet top',time:'8:56 AM',miss:2},
];
const lbGlobal=[
  {name:'Priya Sharma',streak:31,av:'PS',col:'#2ecc71'},
  {name:'Rahul Dev',streak:28,av:'RD',col:'#e74c3c'},
  {name:'Ananya Singh',streak:24,av:'AS',col:'#8e44ad'},
  {name:'Arjun K',streak:12,av:'AK',col:'#00C9B1',me:true},
  {name:'Meera Patel',streak:11,av:'MP',col:'#e67e22'},
  {name:'Karan Verma',streak:9,av:'KV',col:'#16a085'},
];
const lbFriends=[
  {name:'Rohit Bhai',streak:18,av:'RB',col:'#e74c3c'},
  {name:'Arjun K',streak:12,av:'AK',col:'#00C9B1',me:true},
  {name:'Sneha Gupta',streak:8,av:'SG',col:'#8e44ad'},
  {name:'Amit Joshi',streak:5,av:'AJ',col:'#16a085'},
];
const langs=[
  {code:'hi-en',flag:'🇮🇳',name:'Hinglish',script:'हिंदी + English',badge:'Default',live:true,prev:'Chabiyaan uthayi? Hook ke paas dekho! SAMARAN yaad karta hai! 🔑'},
  {code:'hi',flag:'🇮🇳',name:'Hindi',script:'हिंदी',badge:'Live',live:true,prev:'चाबियां उठाईं? हुक के पास देखो — SAMARAN हमेशा याद दिलाता है! 🔑'},
  {code:'en',flag:'🌐',name:'English',script:'English',badge:'Live',live:true,prev:'Keys picked up? Check the hook — SAMARAN reminds you! 🔑'},
  {code:'mr',flag:'🇮🇳',name:'Marathi',script:'मराठी',badge:'Soon',live:false,prev:''},
  {code:'ta',flag:'🇮🇳',name:'Tamil',script:'தமிழ்',badge:'Soon',live:false,prev:''},
  {code:'bn',flag:'🇮🇳',name:'Bengali',script:'বাংলা',badge:'Soon',live:false,prev:''},
  {code:'gu',flag:'🇮🇳',name:'Gujarati',script:'ગુજરાતી',badge:'Soon',live:false,prev:''},
  {code:'pa',flag:'🇮🇳',name:'Punjabi',script:'ਪੰਜਾਬੀ',badge:'Soon',live:false,prev:''},
];
const personaData={
  maa:{label:'🏠 Maa Mode',challenge:{title:'Take Evening Medicine 💊',msg:'Beta! Dawai pi li? Doctor ne bola tha na daily lene ko — SAMARAN yaad karata hai! Abhi le lo!'},done:'Shabash beta — SAMARAN proud hai!',mila:'Chabiyaan uthayi? Hook ke paas dekho bhai — Maa yaad dila rahi hai! 😄'},
  sec:{label:'🏢 Secretary',challenge:{title:'COMPLETE: Medicine Task',msg:'SAMARAN ALERT: Evening medicine pending. Complete it now. Task cannot be snoozed past 10 PM.'},done:'Task complete. Logged. Next item.',mila:'Pre-departure check: Keys, ID, Charger. Confirm all items.'},
};
 
let currentPersona='maa';
let currentLang='hi-en';
let currentScreen='home';
let snoozeCount=0;
let selectedDay=1;
let catFilter='all';
 
// ── CANVAS PARTICLE ──
const canvas=document.getElementById('bgCanvas');
const ctx=canvas.getContext('2d');
let particles=[];
function resizeCanvas(){canvas.width=window.innerWidth;canvas.height=window.innerHeight}
resizeCanvas();
window.addEventListener('resize',resizeCanvas);
for(let i=0;i<60;i++)particles.push({x:Math.random()*window.innerWidth,y:Math.random()*window.innerHeight,r:Math.random()*1.5+.3,vx:(Math.random()-.5)*.3,vy:(Math.random()-.5)*.3,a:Math.random()*.4+.1});
function animateCanvas(){
  ctx.clearRect(0,0,canvas.width,canvas.height);
  particles.forEach(p=>{
    p.x+=p.vx;p.y+=p.vy;
    if(p.x<0)p.x=canvas.width;if(p.x>canvas.width)p.x=0;
    if(p.y<0)p.y=canvas.height;if(p.y>canvas.height)p.y=0;
    ctx.beginPath();ctx.arc(p.x,p.y,p.r,0,Math.PI*2);
    ctx.fillStyle=`rgba(0,201,177,${p.a})`;ctx.fill();
  });
  requestAnimationFrame(animateCanvas);
}
animateCanvas();
 
// ── NAVIGATION ──
const screenMap={home:'sc-home',plan:'sc-plan',mila:'sc-mila',board:'sc-board',set:'sc-set'};
const navMap={home:'ni-home',plan:'ni-plan',mila:'ni-mila',board:'ni-board',set:'ni-set'};
function nav(to){
  const allScreens=Object.values(screenMap);
  const dir=(['home','plan','mila','board','set'].indexOf(to)>['home','plan','mila','board','set'].indexOf(currentScreen))?'right':'left';
  allScreens.forEach(id=>{
    const el=document.getElementById(id);
    if(!el)return;
    el.classList.remove('active','hidden-left','hidden-right');
    el.classList.add('hidden-left');
  });
  const fromEl=document.getElementById(screenMap[currentScreen]);
  const toEl=document.getElementById(screenMap[to]);
  if(fromEl){fromEl.classList.remove('hidden-left');fromEl.classList.add(dir==='right'?'hidden-left':'hidden-right');}
  if(toEl){toEl.classList.remove('hidden-left','hidden-right');toEl.classList.add('active');}
  Object.values(navMap).forEach(id=>document.getElementById(id)?.classList.remove('on'));
  document.getElementById(navMap[to])?.classList.add('on');
  currentScreen=to;
  if(to==='home')renderHome();
  if(to==='plan')renderPlan();
  if(to==='mila')renderMila();
  if(to==='board')renderBoard('global');
  if(to==='set')renderSettings();
}
 
// ── RENDER HOME ──
function renderHome(){
  const today=tasks.filter(t=>t.day===1);
  const visible=catFilter==='all'?today:today.filter(t=>t.cat===catFilter);
  const done=today.filter(t=>t.done).length;
  const pct=Math.round(done/today.length*100);
  document.getElementById('progFill').style.width=pct+'%';
  document.getElementById('taskProgress').textContent=done+' / '+today.length;
  document.getElementById('pctLabel').textContent=pct+'%';
  const feed=document.getElementById('homeFeed');
  feed.innerHTML='';
  visible.forEach(t=>feed.appendChild(makeTaskCard(t)));
}
 
function makeTaskCard(t){
  const d=document.createElement('div');
  const catClass='cat-'+t.cat.toLowerCase();
  const chipClass='chip-'+t.cat.toLowerCase();
  d.className=`task-card ${catClass}${t.done?' done':''}`;
  d.innerHTML=`<div class="check-ring${t.done?' done':''}" onclick="toggleTask(${t.id},event)"></div>
    <div class="task-info">
      <div class="task-name">${t.name}</div>
      <div class="task-meta">
        <span class="task-time">${t.time}</span>
        <span class="cat-chip ${chipClass}">${t.cat}</span>
        <div class="pri-dot p${t.pri}"></div>
      </div>
    </div>`;
  return d;
}
 
function toggleTask(id,e){
  e&&e.stopPropagation();
  const t=tasks.find(x=>x.id===id);
  if(!t)return;
  t.done=!t.done;
  if(currentScreen==='home')renderHome();
  if(currentScreen==='plan')renderPlan();
  if(t.done){showToast('✅ Done!',personaData[currentPersona].done);confetti();}
}
 
function filterCat(cat,btn){
  catFilter=cat;
  document.querySelectorAll('.pill-tabs .pill').forEach(b=>b.classList.remove('on'));
  btn.classList.add('on');
  renderHome();
}
 
// ── RENDER PLANNER ──
function renderPlan(){
  const strip=document.getElementById('weekStrip');
  strip.innerHTML='';
  ['Mon','Tue','Wed','Thu','Fri','Sat','Sun'].forEach((d,i)=>{
    const dt=tasks.filter(t=>t.day===i+1);
    const allDone=dt.length>0&&dt.every(t=>t.done);
    const el=document.createElement('div');
    el.className='wd'+(i+1===selectedDay?' sel':'')+(allDone&&i+1!==selectedDay?' completed':'');
    el.innerHTML=`<div class="wd-name">${d}</div><div class="wd-num">${17+i}</div><div class="wd-done"></div>`;
    el.onclick=()=>{selectedDay=i+1;renderPlan();};
    strip.appendChild(el);
  });
  const days=['Mon','Tue','Wed','Thu','Fri','Sat','Sun'];
  document.getElementById('planDayHead').innerHTML=`<div class="sec-title">${days[selectedDay-1].toUpperCase()} · MAR ${17+selectedDay-1}</div>`;
  const feed=document.getElementById('planFeed');
  feed.innerHTML='';
  const dt=tasks.filter(t=>t.day===selectedDay);
  if(!dt.length){
    feed.innerHTML='<div style="text-align:center;padding:30px;color:var(--text3);font-size:13px">No tasks for this day.<br><span style="color:var(--teal)">Add some below ↓</span></div>';
    return;
  }
  dt.forEach(t=>feed.appendChild(makeTaskCard(t)));
}
 
// ── RENDER MILA ──
function renderMila(){
  document.getElementById('milaMainMsg').innerHTML=currentPersona==='maa'?
    '<strong>Chabiyaan uthayi?</strong> Hook ke paas dekho bhai — SAMARAN yaad dila raha hai! 😄':
    '<strong>Pre-departure check:</strong> Keys, ID, Charger. Confirm all items before leaving.';
  const grid=document.getElementById('milaGrid');
  grid.innerHTML='';
  milaItems.forEach(item=>{
    const d=document.createElement('div');
    d.className='mila-item';
    d.innerHTML=`<div class="mila-item-icon">${item.icon}</div>
      <div class="mila-item-info"><div class="mila-item-name">${item.name}</div><div class="mila-item-loc">📍 ${item.place}</div></div>
      <div class="mila-item-side"><div class="mila-timer">${item.time}</div><div class="mila-miss">${item.miss}× this week</div></div>`;
    grid.appendChild(d);
  });
  document.getElementById('milaReport').innerHTML=
    `🔑 Keys — nearly forgot <span style="color:var(--amber)">4 times</span><br>
     🔌 Charger — nearly forgot <span style="color:var(--amber)">3 times</span><br>
     👛 Wallet — nearly forgot <span style="color:var(--amber)">2 times</span><br>
     <span style="color:var(--teal)">SAMARAN saved you 9 times this week! 🎉</span>`;
}
function milaYes(){showToast('✅ Mila Kya? Cleared',currentPersona==='maa'?'Shabash! Sab le liya — SAMARAN proud!':'Pre-departure check complete. All clear.');confetti();}
function milaNo(){showToast('🔍 Location Hint','Check: Hook near main door — you kept it there yesterday!');}
 
// ── LEADERBOARD ──
function renderBoard(type){
  const data=type==='global'?lbGlobal:lbFriends;
  const top3=data.slice(0,3);
  const pod=document.getElementById('podium');
  pod.innerHTML='';
  const order=[1,0,2];
  order.forEach(i=>{
    if(!top3[i])return;
    const u=top3[i];
    const slot=document.createElement('div');
    slot.className='podium-slot p'+(i+1);
    const medal=['🥇','🥈','🥉'][i];
    const streakCol=['#FFD700','#C0C0C0','#CD7F32'][i];
    slot.innerHTML=`
      <div class="podium-avatar" style="background:${u.col}22;color:${u.col};${i===0?'border:2px solid '+u.col:''}">${u.av}</div>
      <div class="podium-name">${u.name}</div>
      <div class="podium-streak" style="color:${streakCol}">${u.streak}🔥</div>
      <div class="podium-base pb${i+1}">${medal}</div>`;
    pod.appendChild(slot);
  });
  const list=document.getElementById('lbList');
  list.innerHTML='';
  data.slice(3).forEach((u,i)=>{
    const d=document.createElement('div');
    d.className='lb-row'+(u.me?' me-row':'');
    d.innerHTML=`<div class="lb-rank">#${i+4}</div>
      <div class="lb-av" style="background:${u.col}22;color:${u.col}">${u.av}</div>
      <div class="lb-info"><div class="lb-uname">${u.name}${u.me?' <span style="font-size:10px;color:var(--teal);margin-left:4px">YOU</span>':''}</div><div class="lb-detail">${u.streak}-day streak</div></div>
      <div><span class="lb-streak-val">${u.streak}</span><span class="lb-flame">🔥</span></div>`;
    list.appendChild(d);
  });
}
function showLB(type,btn){
  document.querySelectorAll('#sc-board .pill').forEach(b=>b.classList.remove('on'));
  btn.classList.add('on');
  renderBoard(type);
}
 
// ── SETTINGS ──
function renderSettings(){
  const ll=document.getElementById('langList');
  ll.innerHTML='';
  langs.forEach(l=>{
    const d=document.createElement('div');
    d.className='lang-row'+(l.code===currentLang?' active':'')+(l.live?'':' locked');
    d.innerHTML=`<div class="lang-flag">${l.flag}</div>
      <div class="lang-row-info">
        <div style="display:flex;align-items:center;gap:8px"><div class="lang-row-name">${l.name}</div><span class="lang-badge ${l.live?'lb-live':'lb-soon'}">${l.badge}</span></div>
        <div class="lang-row-script">${l.script}</div>
        ${l.live&&l.prev?`<div class="lang-row-preview">"${l.prev.substring(0,42)}…"</div>`:''}
      </div>
      <div class="lang-check">${l.code===currentLang?'✓':''}</div>`;
    if(l.live)d.onclick=()=>setLang(l.code);
    ll.appendChild(d);
  });
  const lp=langs.find(l=>l.code===currentLang);
  document.getElementById('langPreviewText').textContent=lp?.prev||'';
  updatePersonaCards();
}
 
function setLang(code){
  currentLang=code;
  const l=langs.find(x=>x.code===code);
  showToast('🌐 Language',`Switched to ${l?.name}`);
  renderSettings();
}
 
function setPers(p){
  currentPersona=p;
  document.getElementById('personaPill').innerHTML=`<span>${personaData[p].label}</span>`;
  updatePersonaCards();
  showToast(p==='maa'?'🏠 Maa Mode Active':'🏢 Secretary Active',p==='maa'?'SAMARAN ab Maa ki tarah baat karega!':'SAMARAN will speak like your secretary.');
}
 
function updatePersonaCards(){
  document.getElementById('pcMaa').className='persona-card pc-maa'+(currentPersona==='maa'?' active':'');
  document.getElementById('pcSec').className='persona-card pc-sec'+(currentPersona==='sec'?' active':'');
  document.getElementById('pcMaaBadge').style.display=currentPersona==='maa'?'block':'none';
  document.getElementById('pcSecBadge').style.display=currentPersona==='sec'?'block':'none';
}
 
function nextPersona(){
  setPers(currentPersona==='maa'?'sec':'maa');
}
 
// ── CHALLENGE ──
function openChallenge(){
  const d=personaData[currentPersona].challenge;
  document.getElementById('csTitle').textContent=d.title;
  document.getElementById('csMsg').textContent=d.msg;
  snoozeCount=0;
  document.getElementById('sp1').classList.remove('used');
  document.getElementById('sp2').classList.remove('used');
  document.getElementById('snoozeBtn').disabled=false;
  document.getElementById('snoozeBtn').style.opacity='1';
  document.getElementById('challengeOverlay').classList.add('open');
}
function challengeDone(){
  document.getElementById('challengeOverlay').classList.remove('open');
  showToast('🔥 Challenge Complete!',personaData[currentPersona].done);
  confetti();
}
function challengeSnooze(){
  snoozeCount++;
  document.getElementById('sp'+snoozeCount).classList.add('used');
  if(snoozeCount>=2){
    document.getElementById('csMsg').textContent=currentPersona==='maa'?'Yaar seriously?? Teesri baar?? SAMARAN tujhe bhoolne NAHI dega — ABHI KAR LO!!':'FINAL OVERRIDE: No more snoozes. Complete this task NOW. SAMARAN locked.';
    document.getElementById('snoozeBtn').disabled=true;
    document.getElementById('snoozeBtn').style.opacity='.3';
  } else {
    document.getElementById('challengeOverlay').classList.remove('open');
    showToast('⏰ Snoozed 10 min',currentPersona==='maa'?'Theek hai beta, sirf ek baar aur!':'Last snooze. Final reminder incoming.');
    setTimeout(openChallenge,4000);
  }
}
 
// ── ORB ──
function orbClick(){
  confetti();
  showToast('🔥 12-Day Streak!',currentPersona==='maa'?'Aaj bhi sab karo beta — SAMARAN tumhara intezaar kar raha hai!':'Execute all tasks today. Maintain the streak.');
}
 
// ── TOAST ──
function showToast(top,bot,dur=3200){
  const el=document.getElementById('toastEl');
  document.getElementById('toastTop').textContent=top;
  document.getElementById('toastBot').textContent=bot;
  el.classList.add('show');
  setTimeout(()=>el.classList.remove('show'),dur);
}
const toast=showToast;
 
// ── CONFETTI ──
function confetti(){
  const wrap=document.getElementById('confWrap');
  wrap.innerHTML='';
  const cols=['#00C9B1','#FFAA00','#FF4F6A','#AA8FFF','#6BCB77','#00A896'];
  for(let i=0;i<36;i++){
    const c=document.createElement('div');
    c.className='cp';
    c.style.cssText=`left:${20+Math.random()*60}%;width:${6+Math.random()*6}px;height:${6+Math.random()*6}px;background:${cols[i%cols.length]};animation-duration:${1.4+Math.random()*.8}s;animation-delay:${Math.random()*.4}s`;
    wrap.appendChild(c);
  }
  setTimeout(()=>wrap.innerHTML='',3000);
}
 
// ── INIT ──
renderHome();
setTimeout(()=>showToast('स्मरण SAMARAN','Remember Everything. Miss Nothing. 🔥'),600);
</script>
</body>
</html>
 
